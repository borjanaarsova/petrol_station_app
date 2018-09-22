#include <iostream>
using namespace std;
class Gorivo //osnovna klasa Gorivo - apstraktna
{
	private: //privatni atributi
		int kolicina; //privaten atribut
		int cena; //privaten atribut
		static int kapacitet; //staticen atribut
		static int ddv; //staticen atribut
	public: //javni metodi
		Gorivo(){} //default konstruktor
		~Gorivo(){} //destruktor
		void set_kolicina(int k); //deklaracija na metoda
		int get_kolicina(); //deklaracija na metoda
		void set_cena(int c); //deklaracija na metoda
		int get_cena(); //deklaracija na metoda
		static void set_ddv(int vrednost) //staticna metoda
		{
			ddv=vrednost; //go setira atributot ddv
		}
		static int get_ddv() //staticna metoda
		{
			return ddv; //go vrakja atributot ddv
		}
		static void set_kapacitet(int vrednost) //staticna metoda
		{
			kapacitet=vrednost; //go setira atributot kapacitet
		}
		static int get_kapacitet() //staticna metoda
		{
			return kapacitet; //go vrakja atributot kapacitet
		}
		void zgolemi_kolicina(int pomosna); //deklaracija na metoda
		void namali_kolicina(int pomosna); //deklaracija na metoda
		virtual void dodaj(int &Broj)=0; //cista virtuelna funkcija
		virtual void odzemi(int &Broj1,int &Broj2)=0; //cista virtuelna funkcija
		virtual void sostojba()=0; //cista virtuelna funkcija
};
int Gorivo::ddv=0; //setiranje na ddv na 0
int Gorivo::kapacitet=0; //setiranje na kapacitet na 0
void Gorivo::set_cena(int c) //definicija na metoda
		{
			cena=c; //go setira atributot cena
		}
int Gorivo::get_cena() //definicija na metoda
		{
			return cena; //go vrakja atributot cena
		}
void Gorivo::set_kolicina(int k) //definicija na metoda
		{
			kolicina=k; //go setira atributot kolicina
		}
int Gorivo::get_kolicina() //definicija na metoda
		{
			return kolicina; //go vrakja atributot kolicina
		}
void Gorivo::zgolemi_kolicina(int pomosna) //definicija na metoda
		{
			kolicina+=pomosna; //go zgolemuva atributot kolicina
		}
void Gorivo::namali_kolicina(int pomosna) //definicija na metoda
		{
			kolicina-=pomosna; //go namaluva atributot kolicina
		}
class Benzin:public Gorivo //izvedena klasa Benzin, public nasleduvanje od Gorivo
{
	public: //javni metodi
		Benzin() //default konstruktor
		{
			set_kolicina(100000); //gi setira atributite
			set_kapacitet(500000); //na pocetni vrednosti
			set_ddv(18);
			set_cena(73);
		}
		~Benzin(){} //destruktor
		virtual void sostojba() //definicija na virtuelna funkcija
		{
			cout<<"Momentalna sostojba na Benzin:"<<endl;
			cout<<"kolicina: "<<get_kolicina()<<" litri"<<endl;
			cout<<"kapacitet: "<<get_kapacitet()<<" litri"<<endl;
			cout<<"ddv: "<<get_ddv()<<"%"<<endl;
			cout<<"cena: "<<get_cena()<<" denari/litar"<<endl;
		}
		virtual void dodaj(int &Broj) //definicija na virtuelna funkcija 
		{ //brojot sto vleguva e broj na dodavanja na benzin
			int pomosna;
			cout<<"Dopolnuvanje na benzin"<<endl;
			cout<<"Vnesi kolku litri benzin sakas da dopolnis: ";
			cin>>pomosna;
			try //isklucok
			{
			if(get_kolicina()+pomosna>get_kapacitet())
			throw 'a';
			else
			throw 1;
			}
			catch (char c)
			{
				cout<<"Ne e dozvolen vnes nad maksimalniot kapacitet!"<<endl;
				cout<<"Obidete se povtorno!"<<endl;
			}
			catch (int i)
			{
				zgolemi_kolicina(pomosna);
				Broj++;
				cout<<"Dodadovte "<<pomosna<<" litri!"<<endl;
			}	
		}
		virtual void odzemi(int &Broj1,int &Broj2) //definicija na virtuelna funkcija
		{ //prviot broj e broj na fiskalna, vtoriot broj e broj na Kasa
			cout<<"Vnesi kolku litri benzin sakas da izvadis: "<<endl;
			int pomosna;
			cin>>pomosna;
			try //isklucok
			{
			if(get_kolicina()<pomosna)
			throw 'a';
			else
			throw 1;
			}
			catch(char c)
			{
				cout<<"Nema dovolno benzin!"<<endl;
				cout<<"Obidete se povtorno!"<<endl;
			}
			catch(int i)
			{
			cout<<"FISKALNA SMETKA BR. "<<++Broj1<<endl;
			cout<<"Benzinska pumpa Mak Petrol"<<endl;
			cout<<"Benzin "<<pomosna<<" l * "<<get_cena()<<" den"<<endl;
			cout<<"Vkupno za plakjanje: "<<pomosna*get_cena()<<" denari"<<endl;
			cout<<"ddv: "<<get_ddv()<<"%"<<endl;
			cout<<"cena: "<<get_cena()<<" denari/litar"<<endl;
			cout<<"kolicina: "<<pomosna<<" litri"<<endl;
			cout<<"Blagodarime za uslugata!"<<endl;
			Broj2+=pomosna*get_cena();
			namali_kolicina(pomosna);
			}
		}
};
class Dizel:public Gorivo //izvedena klasa Dizel, public nasleduvanje od Gorivo
{
	public: //javni metodi
		Dizel() //default konstruktor
		{
			set_kolicina(100000);
			set_kapacitet(500000);
			set_ddv(18);
			set_cena(65);
		}
		~Dizel(){} //destruktor
	virtual void sostojba() //definicija na virtuelna funkcija
		{
			cout<<"Momentalna sostojba na Dizel:"<<endl;
			cout<<"kolicina: "<<get_kolicina()<<" litri"<<endl;
			cout<<"kapacitet: "<<get_kapacitet()<<" litri"<<endl;
			cout<<"ddv: "<<get_ddv()<<"%"<<endl;
			cout<<"cena: "<<get_cena()<<" denari/litar"<<endl;
		}
		virtual void dodaj(int &Broj) //definicija na virtuelna funkcija
		{ //brojot sto vleguva e broj na dodavanja na benzin
			int pomosna;
			cout<<"Dopolnuvanje na dizel"<<endl;
			cout<<"Vnesi kolku litri dizel sakas da dopolnis: ";
			cin>>pomosna;
			try //isklucok
			{
			if(get_kolicina()+pomosna>get_kapacitet())
			throw 'a';
			else
			throw 1;
			}
			catch (char c)
			{
				cout<<"Ne e dozvolen vnes nad maksimalniot kapacitet!"<<endl;
				cout<<"Obidete se povtorno!"<<endl;
			}
			catch (int i)
			{
				zgolemi_kolicina(pomosna);
				Broj++;
				cout<<"Dodadovte "<<pomosna<<" litri!"<<endl;
			}	
		}
		virtual void odzemi(int &Broj1,int &Broj2) //definicija na virtuelna funkcija
		{ //prviot broj e broj na fiskalna, vtoriot broj e broj na Kasa
			cout<<"Vnesi kolku litri dizel sakas da izvadis: "<<endl;
			int pomosna;
			cin>>pomosna;
			try //isklucok
			{
			if(get_kolicina()<pomosna)
			throw 'a';
			else
			throw 1;
			}
			catch(char c)
			{
				cout<<"Nema dovolno dizel!"<<endl;
				cout<<"Obidete se povtorno!"<<endl;
			}
			catch(int i)
			{
			cout<<"FISKALNA SMETKA BR. "<<++Broj1<<endl;
			cout<<"Benzinska pumpa Mak Petrol"<<endl;
			cout<<"Dizel "<<pomosna<<" l * "<<get_cena()<<" den"<<endl;
			cout<<"Vkupno za plakjanje: "<<pomosna*get_cena()<<" denari"<<endl;
			cout<<"ddv: "<<get_ddv()<<"%"<<endl;
			cout<<"cena: "<<get_cena()<<" denari/litar"<<endl;
			cout<<"kolicina: "<<pomosna<<" litri"<<endl;
			cout<<"Blagodarime za uslugata!"<<endl;
			Broj2+=pomosna*get_cena();
			namali_kolicina(pomosna);
			}
		}
};
class Plin:public Gorivo //izvedena klasa Plin, public nasleduvanje od Gorivo
{
	public:
		Plin() //default konstruktor
		{
			set_kolicina(100000);
			set_kapacitet(500000);
			set_ddv(18);
			set_cena(25);
		}
		~Plin(){} //destruktor
		virtual void sostojba() //definicija na virtuelna funkcija
		{
			cout<<"Momentalna sostojba na Plin:"<<endl;
			cout<<"kolicina: "<<get_kolicina()<<" litri"<<endl;
			cout<<"kapacitet: "<<get_kapacitet()<<" litri"<<endl;
			cout<<"ddv: "<<get_ddv()<<"%"<<endl;
			cout<<"cena: "<<get_cena()<<" denari/litar"<<endl;
		}
		virtual void dodaj(int &Broj)
		{ //brojot sto vleguva e broj na dodavanja na benzin
			int pomosna;
			cout<<"Dopolnuvanje na plin"<<endl;
			cout<<"Vnesi kolku litri plin sakas da dopolnis: ";
			cin>>pomosna;
			try //isklucok
			{
			if(get_kolicina()+pomosna>get_kapacitet())
			throw 'a';
			else
			throw 1;
			}
			catch (char c)
			{
				cout<<"Ne e dozvolen vnes nad maksimalniot kapacitet!"<<endl;
				cout<<"Obidete se povtorno!"<<endl;
			}
			catch (int i)
			{
				zgolemi_kolicina(pomosna);
				Broj++;
				cout<<"Dodadovte "<<pomosna<<" litri!"<<endl;
			}
		}
		virtual void odzemi(int &Broj1,int &Broj2) //definicija na virtuelna funkcija
		{ //prviot broj e broj na fiskalna, vtoriot broj e broj na Kasa
			cout<<"Vnesi kolku litri plin sakas da izvadis: "<<endl;
			int pomosna;
			cin>>pomosna;
			try //isklucok
			{
			if(get_kolicina()<pomosna)
			throw 'a';
			else
			throw 1;
			}
			catch(char c)
			{
				cout<<"Nema dovolno plin!"<<endl;
				cout<<"Obidete se povtorno!"<<endl;
			}
			catch(int i)
			{
			cout<<"FISKALNA SMETKA BR. "<<++Broj1<<endl;
			cout<<"Benzinska pumpa Mak Petrol"<<endl;
			cout<<"Plin "<<pomosna<<" l * "<<get_cena()<<" den"<<endl;
			cout<<"Vkupno za plakjanje: "<<pomosna*get_cena()<<" denari"<<endl;
			cout<<"ddv: "<<get_ddv()<<"%"<<endl;
			cout<<"cena: "<<get_cena()<<" denari/litar"<<endl;
			cout<<"kolicina: "<<pomosna<<" litri"<<endl;
			cout<<"Blagodarime za uslugata!"<<endl;
			Broj2+=pomosna*get_cena();
			namali_kolicina(pomosna);
			}
		}
};
int main () //glavna programa
{
	Benzin *B=new Benzin; //kreiranje dinamicki objekti
	Dizel *D=new Dizel;
	Plin *P=new Plin;
	int Kasa=0; //sostojbata na pari vo kasata na pocetokot e nula
	int Broj_na_smetka=0; //brojot na fiskalni smetki e nula
	int Broj_na_dopolnuvanja=0; //brojot na dodavanje na gorivo e nula
	int i=1; //se koristi za glavnoto meni
	cout<<"Dobrodojdovte na Benzinskata Pumpa na Mak Petrol!"<<endl;
	cout<<"Pocetnata sostojba na naftenite derivati e slednata:"<<endl;
	B->sostojba(); //se pecati sostojba za kreiranite objekti
	D->sostojba();
	P->sostojba();
	while(i!=0) //glavno meni
	{
	cout<<"Glavno meni:"<<endl;
	cout<<"1. Dopolni gorivo (od cisterna)"<<endl;
	cout<<"2. Izvadi gorivo (vo motorno vozilo)"<<endl;
	cout<<"3. Promeni cena/kapacitet/ddv"<<endl;
	cout<<"4. Momentalna sostojba"<<endl;
	cout<<"0. Izlez"<<endl;
	cout<<"Pristapi do: ";
	cin>>i;
	if(i==1) //ovde se dodava gorivo vo rezervoarite na benzinskata
	{
		cout<<"Dojde cisterna so gorivo!"<<endl;
		int i;
		cout<<"1. Dopolni Benzin"<<endl;
		cout<<"2. Dopolni Dizel"<<endl;
		cout<<"3. Dopolni Plin"<<endl;
		cout<<"Pristapi do: ";
		cin>>i;
		if(i==1)
			B->dodaj(Broj_na_dopolnuvanja);
		if(i==2)
			D->dodaj(Broj_na_dopolnuvanja);
		if(i==3)
			P->dodaj(Broj_na_dopolnuvanja);
	}
	if(i==2) //ovde se tochi gorivo vo motornite vozila
	{
		cout<<"Polnenje na gorivo vo motorno vozilo"<<endl;
		int i;
		cout<<"1. Dopolni Benzin"<<endl;
		cout<<"2. Dopolni Dizel"<<endl;
		cout<<"3. Dopolni Plin"<<endl;
		cout<<"Pristapi do: ";
		cin>>i;
		if(i==1)
			B->odzemi(Broj_na_smetka,Kasa);
		if(i==2)
			D->odzemi(Broj_na_smetka,Kasa);
		if(i==3)
			P->odzemi(Broj_na_smetka,Kasa);
	}
	if(i==3) //ovde se vrsi promena na cena/kapacitet/ddv
	{
		cout<<"Promena na podatoci"<<endl;
		int i;
		cout<<"1. Promena na cena"<<endl;
		cout<<"2. Promena na kapacitet"<<endl;
		cout<<"3. Promena na ddv"<<endl;
		cout<<"Pristapi do: ";
		cin>>i;
		if(i==1) //promena na cena
		{
			cout<<"Promena na cena na:"<<endl;
			int i;
			cout<<"1. Benzin"<<endl;
			cout<<"2. Dizel"<<endl;
			cout<<"3. Plin"<<endl;
			cout<<"Pristapi do: ";
			cin>>i;
			if(i==1)
			{
				cout<<"Vnesi ja novata cena na Benzinot: "<<endl;
				int pomosna;
				cin>>pomosna;
				B->set_cena(pomosna);
				cout<<"Novata cena na Benzinot e "<<B->get_cena()<<" denari/litar!"<<endl;
			}
			if(i==2)
			{
				cout<<"Vnesi ja novata cena na Dizelot: "<<endl;
				int pomosna;
				cin>>pomosna;
				D->set_cena(pomosna);
				cout<<"Novata cena na Dizelot e "<<D->get_cena()<<" denari/litar!"<<endl;	
			}
			if(i==3)
			{
				cout<<"Vnesi ja novata cena na Plinot: "<<endl;
				int pomosna;
				cin>>pomosna;
				P->set_cena(pomosna);
				cout<<"Novata cena na Plinot e "<<P->get_cena()<<" denari/litar!"<<endl;
			}
		}
		if(i==2) //promena na kapacitet
		{
			cout<<"Promena na kapacitet"<<endl;
			cout<<"Vnesi go noviot kapacitet na benzinskata stanica: ";
			int pomosna;
			cin>>pomosna;
			Gorivo::set_kapacitet(pomosna);
			cout<<"Noviot kapacitet na benzinskata stanica e "<<Gorivo::get_kapacitet()<<" litri."<<endl;
		}
		if(i==3) //promena na ddv
		{
			cout<<"Promena na ddv"<<endl;
			cout<<"Vnesi ja novata vrednost na ddv-danok na dodadena vrednost (vo procenti): ";
			int pomosna;
			cin>>pomosna;
			Gorivo::set_ddv(pomosna);
			cout<<"Novata vrednost na ddv e "<<Gorivo::get_ddv()<<"%."<<endl;
		}
	}
	if (i==4)
	{
		cout<<"Momentalna sostojba na:"<<endl;
		cout<<"1. Gorivo"<<endl;
		cout<<"2. Izdadeni fiskalni smetki"<<endl;
		cout<<"3. Pari vo kasa"<<endl;
		int i;
		cout<<"Pristapi do: ";
		cin>>i;
		if(i==1)
		{
			cout<<"Momentalnata sostojba na naftenite derivati e slednata:"<<endl;
			B->sostojba();
			D->sostojba();
			P->sostojba();
		}
		if(i==2)
		{
			cout<<"Brojot na izdadeni fiskalni smetki e "<<Broj_na_smetka<<endl;
		}
		if(i==3)
		{
			cout<<"Momentalniot iznos na pari vo kasata e "<<Kasa<<endl;
		}
	}
    cout<<endl;
	}
	cout<<"Izlegovte od programata!"<<endl;
	delete B; //unistuvanje na dinamicki objekti
	delete D;
	delete P;
	return 0;
}
