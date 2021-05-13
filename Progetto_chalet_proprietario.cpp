#include <iostream>

#include <fstream>

#include <iomanip>

#define nombrelloni 100

using namespace std;
fstream out;

struct ombrellone {
  int numero;
  char cognome[15];
  int lettini;
  float saldo;
  int inizio;
  ombrellone * succ;

};

typedef ombrellone * ombrelloni;

void inserisci(ombrellone & a) {

  cout << "numero ombrellone: ";
  cin >> a.numero;
  cout << endl;

  cout << "cognome: ";
  cin >> a.cognome;
  cout << endl;

  cout << "numero lettini: ";
  cin >> a.lettini;
  cout << endl;

  cout << "saldo: ";
  cin >> a.saldo;
  cout << endl;

  cout << "inizio: ";
  cin >> a.inizio;
  cout << endl;
  return;
}



void archivia_ord(ombrelloni & inizio, ombrellone a) {
  ombrelloni p, q, r;
  for (p = inizio; p != 0 && p -> numero < a.numero; p = p -> succ) q = p;
  r = new ombrellone;
  * r = a;
  r -> succ = p;
  if (p == inizio) inizio = r;
  else q -> succ = r;
  return;
}

void elimina(ombrelloni &inizio, ombrelloni p_el){
	ombrelloni p,q;
	for (p = inizio; p!=p_el ; p = p -> succ)q=p;
	if(p==inizio)inizio=p->succ;
	else q->succ=p->succ;
	delete p;
	
}

void modifica(ombrelloni & inizio, int a) {
  char r;
  ombrelloni p, q;

  for (p = inizio; p != 0 && p -> numero != a; p = p -> succ)
    q = p;

  do {
    cout << "cosa vuoi fare?....cambiare numero[c],cambiare dati del ombrellone[d],niente[n]" << endl;
    cin >> r;
    if (r == 'n') {
      return ;
    }
    if (r == 'c') {
      cout << "inserisci nuovo num:";
      ombrellone b;
      cin >> b.numero;
      cout << endl;
      cout << "inserisci il cognome:";
      cin >> b.cognome;
      b.lettini = p -> lettini;
      b.saldo = p -> saldo;
      b.inizio = p -> inizio;
	  archivia_ord(inizio, b);
      elimina(inizio,p);
      
    }
    if (r == 'd') {
      do {
        char r1;
        cout << "cambiare cognome[c],cambiare lettini[l],cambiare saldo[s],cambiare inizio[i],finito[f]" << endl;
        cin >> r1;
        if (r1 == 'c') {
          cout << "nuovo cognome:";
          cin >> p -> cognome;
          cout << endl;
        }
        if (r1 == 'l') {
          cout << "nuovi lettini:";
          cin >> p -> lettini;
          cout << endl;
        }
        if (r1 == 's') {
          cout << "nuovo saldo:";
          cin >> p -> saldo;
          cout << endl;
        }
        if (r1 == 'i') {
          cout << "nuovo inizio:";
          cin >> p -> inizio;
          cout << endl;
        }
        if (r1 == 'f') {
          return ;
        }

      } while (r != 'i' || r != 'c' || r != 's' || r != 'l' || r != 'f');
    }

  } while (r != 'd' || r != 'c');
}

void stampa(ombrelloni p) {
  cout << "NUMERO   COGNOME          LETTINI   SALDO   INIZIO" << endl;
  while (p != 0) {
    cout.setf(ios::left, ios::adjustfield);
    cout << setfill(' ') << setw(9) << p -> numero << setw(17) << p -> cognome << setw(10) << p -> lettini << setw(9) << p -> saldo << p -> inizio << endl;
    p = p -> succ;
  }
}

void stampa_file(ombrelloni p) {
	out.open("spiaggia",ios::out);
 out << "NUMERO   COGNOME          LETTINI   SALDO   INIZIO" << endl;
  while (p != 0) {
    out.setf(ios::left, ios::adjustfield);
    out << setfill(' ') << setw(9) << p -> numero << setw(17) << p -> cognome << setw(10) << p -> lettini << setw(9) << p -> saldo << p -> inizio << endl;
    p = p -> succ;
  }
  out.close();
}

void dati(ombrelloni  & inizio){
	out.open("spiaggia",ios::in);
	ombrellone el;
	char a[7];char b[8];char c[8];char d[6];char e[7];
	out>>a>>b>>c>>d>>e;
	while(out.good()){
		out>>el.numero>>el.cognome>>el.lettini >> el.saldo >>el.inizio;
		archivia_ord( inizio, el);
	}
	out.close();
	return;
}


int main() {
  ombrellone n;
  ombrelloni agenda = 0;
  dati(agenda);
  int f = 0;
  char r = 'i';
  do {
    cout << "vuoi fare?" << endl;
    cout << "inserire[i]" << endl;
    cout << "vedi[v]" << endl;
    cout << "stampare[s]" << endl;
    cout << "modifica[m]" << endl;
    cout << "sapere numero ombrelloni disponibili[n]" << endl;
    cout << "uscire[u]" << endl;
    cin >> r;
    if (r == 'i') {
      inserisci(n);
      archivia_ord(agenda, n);
      f++;
    }
    if (r == 'n') {
      cout << "ci sono " << nombrelloni - f << " disponibili" << endl;
    }
    if (r == 'v') {
      stampa(agenda);
      stampa_file(agenda);
    }
    if (r == 's') {
      stampa_file(agenda);
    }
    if (r == 'm') {
      if (agenda == 0) {
        cout << "spiaggia vuota" << endl << endl;
      } else {
        cout << "Numero ombrellone da modificare:";
        int a;
        cin >> a;
        modifica(agenda, a);
      }
    }
    if (r == 'u') {
      return 0;
    }
  }
  while (r != 'i' || r != 'n' || r != 's' || r != 'u' || r != 'v');

  return 0;
}


/*bool controlla(ombrelloni inizio,ombrellone a){
	ombrelloni p;
	for (p = inizio; p != 0 && p -> numero==a.numero; p = p -> succ)
	if(p==0) return true;
	if(p -> numero==a.numero)return false;
}*/
