#include <iostream>

class Nod{
    private:
        char info;
        Nod *next;
    public:
        Nod()
        {
            info = '\0';
            next = NULL;
        }
        Nod(char info)
        {
            this->info = info;
            this->next = NULL;
        }
        Nod(char info, Nod *next)
        {
            this->info = info;
            this->next = next;
        }
		Nod(const Nod &n)
		{
			this->info = n.info;
			this->next = n.next;
		}

        char GetInfo()
        {
            return this->info;
        }

        Nod *GetNext()
        {
            return this->next;
        }

        void SetInfo(char info)
        {
            this->info = info;
        }

        void SetNext(Nod *next)
        {
            this->next = next;
        }


        ~Nod()
        {
            this->info = '\0';
			this->next = NULL;
        }
};


class Coada_de_caractere{
    private:
        Nod *first;
        Nod *last;
    public:
        Coada_de_caractere()
        {
            first = NULL;
            last = NULL;
        }
		
		Coada_de_caractere(Nod *first)
		{
			this->first = first;
		}
		
		Coada_de_caractere(Nod *first, Nod *last)
		{
			this->first = first;
			this->last = last;
		}
		
		Coada_de_caractere(const Coada_de_caractere &c) {
			// Nu se pot apela functii publice din interiorul construtorului
			// Am incercat si prin push() dar nu a functionat deoarece a rezultat intr-o eroare, Segmentation Fault
			Nod *cursour = c.first;
			this->first = new Nod;
			this->first->SetInfo(cursour->GetInfo());
			this->last = this->first;
			cursour = cursour->GetNext();
			while(cursour != NULL)
			{
				Nod *n = new Nod;
				this->last->SetNext(n);
				this->last->GetNext()->SetInfo(cursour->GetInfo());
				this->last = this->last->GetNext();
				this->last->SetNext(NULL);
				cursour = cursour->GetNext();
			}
			
		}
		
		
		Nod *GetFirst()
		{
			return this->first;
		}
		
		Nod *GetLast()
		{
			return this->last;
		}
		
		void SetFirst(Nod *first)
		{
			this->first = first;
		}
		
		void SetLast(Nod *last)
		{
			this->last = last;
		}

        bool isempty()
        {
            if(first == NULL)
                return true;

            return false;
        }

        void push(char c)
        {
            if(this->isempty())
            {
                this->first = new Nod;
                this->first->SetInfo(c);
                this->last = this->first;
            }
            else
            {
                Nod *n = new Nod;
                this->last->SetNext(n);
                this->last->GetNext()->SetInfo(c);
                this->last = this->last->GetNext();
                this->last->SetNext(NULL);
            }
        }

        char pop()
        {
            if(this->isempty())
            {
                //std::cout<<"Nu se pot sterge mai multe elemente!";
                return '\0';
            }

            char c = this->first->GetInfo();
            if(this->last == this->first)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
                return c;
            }

            Nod *sfirst = this->first->GetNext(); // salvam elementul de pe o pozitie in fata
            delete this->first; // stergem primul element
            this->first = sfirst; // punem al doilea element ca fiind primul

            return c;
        }
		
		// Codul de dinainte sa stiu raspunsul la intrebari
		/*
        void pop(int position)
        {
            Nod *cursour = this->first;
            // Ne ducem cu o pozitie in spate fata de elementul pe care dorim sa il stergem
            for(int i = 1; i <= position-1 && cursour->GetNext() != NULL; i++)
            {
                cursour = cursour->GetNext();
            }

            if(cursour->GetNext() == NULL)
            {
                std::cout<<"Acest element iese din lista!\n";
                return;
            }

            Nod *skiped = cursour->GetNext()->GetNext();
            delete cursour->GetNext();// stergem pozitia
            cursour->SetNext(skiped);// Setam urmatorul element ca fiind 2 pozitii mai in fata
        }
		 */

        friend std::ostream& operator<<(std::ostream &out, Coada_de_caractere &coada);
        friend std::istream& operator>>(std::istream &in, const Coada_de_caractere &coada);


        Coada_de_caractere operator+(Coada_de_caractere const &coada)
        {
            Coada_de_caractere result;

            Nod *cursour = this->first;
            while(cursour != NULL)
            {
                result.push(cursour->GetInfo());
                cursour = cursour->GetNext();
            }
            cursour = coada.first;
            while(cursour != NULL)
            {
                result.push(cursour->GetInfo());
                cursour = cursour->GetNext();
            }

            return result;
        }

        Coada_de_caractere operator-(Coada_de_caractere const &coada)
        {
            Coada_de_caractere result;
            Nod *cursourLeft = this->first;
            Nod *cursourRight = coada.first;
            while(cursourLeft != NULL && cursourRight != NULL)
            {
                if(cursourLeft->GetInfo() > cursourRight->GetInfo())
                    result.push(cursourLeft->GetInfo());
                else
                    result.push(cursourRight->GetInfo());

                cursourLeft = cursourLeft->GetNext();
                cursourRight = cursourRight->GetNext();
            }
            return result;
        }
		
		Coada_de_caractere operator=(Coada_de_caractere const &coada)
		{
			while(!this->isempty()) // stergem toate elementele curente din coada
				this->pop();
			Nod *cursour = coada.first;
			while(cursour != NULL) // adaugam elementele din noua coada
			{
				this->push(cursour->GetInfo());
				cursour = cursour->GetNext();
			}
			
			
			return *this;
		}
		
		bool operator==(const Coada_de_caractere &rightQueue)
		{
			Nod *leftQueueCursor = this->first;
			Nod *rightQueueCursor = rightQueue.first;
			
			while(leftQueueCursor != NULL && rightQueueCursor != NULL)
			{
				if(leftQueueCursor->GetInfo() != rightQueueCursor->GetInfo())
					return false;
				
				leftQueueCursor = leftQueueCursor->GetNext();
				rightQueueCursor = rightQueueCursor->GetNext();
			}
			
			if(leftQueueCursor == NULL && rightQueueCursor == NULL)
				return true;
			
			return false;
		}

        ~Coada_de_caractere()
        {
            Nod *cursour = this->first;
            while(cursour != NULL)
            {
                Nod *next_position = cursour->GetNext();
                delete cursour;
                cursour = next_position;
            }

        }
};

std::ostream& operator<<(std::ostream &out, Coada_de_caractere &coada)
{
    Nod *cursour = coada.first;
	while(cursour != NULL)
	{
		std::cout<<cursour->GetInfo()<<" ";
		cursour = cursour->GetNext();
		coada.pop();
	}
	
    return out;
}

std::istream& operator>>(std::istream &in, Coada_de_caractere &coada)
{
	int n;
	std::cout<<"Cate caractere doriti sa cititi pentru aceasta coada?\n";
	std::cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		char c;
		std::cout<<"Introduceti un caracter: ";
		in>>c;
		coada.push(c);
	}
    return in;
}


void demoQueues()
{
	Coada_de_caractere coada;
    Coada_de_caractere coada2;

    std::cin>>coada>>coada2;
	
	
	Coada_de_caractere coada3 = coada + coada2;
	Coada_de_caractere coada4 = coada - coada2;
	std::cout<<"The addition of queues: "<<coada3<<std::endl;
	std::cout<<"The subtraction of queues: "<<coada4<<std::endl;
	
	
	// eliminam cate 2 elemente din coada
	std::cout<<"first pop() on first queue: "<<coada.pop()<<std::endl;
	std::cout<<"second pop() on first queue: "<<coada.pop()<<std::endl;
	std::cout<<"first pop() on second queue: "<<coada2.pop()<<std::endl;
	std::cout<<"sencond pop() on second queue: "<<coada2.pop()<<std::endl;
	
	
	Coada_de_caractere s1(coada);
	Coada_de_caractere s2(coada2);
	std::cout<<"First queue: ";
	std::cout<<coada<<std::endl;
	std::cout<<"Second queue: ";
	std::cout<<coada2<<std::endl;
	
	coada = s1;
	coada2 = s2;
	
	
	std::cout<<"Testing == operator... coada == coada2"<<std::endl;
	if(coada == coada2)
		std::cout<<"Queues are equal"<<std::endl;
	else
		std::cout<<"Queues are not equal"<<std::endl;
	
	std::cout<<"Testing assign operator... coada = coada2"<<std::endl;
	coada = coada2;
	
	std::cout<<"Printing both queues"<<std::endl;
	std::cout<<coada<<std::endl;
	std::cout<<coada2<<std::endl;
	

	
}


void menu()
{
	std::cout<<"1. Cititi, memorati si afisati n cozi ."<<std::endl;
	std::cout<<"2. Testati metodele si operatorii."<<std::endl;
	std::cout<<"3. Totatul cozilor memorate."<<std::endl;
	std::cout<<"4. Adaugati doua cozi memorate."<<std::endl;
	std::cout<<"5. Scadeti doua cozi memorate."<<std::endl;
	std::cout<<"6. Inchide programul."<<std::endl;
}


void showQueues(Coada_de_caractere *cozi, unsigned int n)
{
	std::cout<<"Cozile memorate sunt acestea: "<<std::endl;
	for(int i = 0; i<n; i++)
	{
		Coada_de_caractere scoada(cozi[i]); // salvam coada deoarece << sterge elementele
		std::cout<<i+1<<". "<<cozi[i]<<std::endl;
		cozi[i] = scoada; 
		// Am fost nevoit sa supraincarc operatorul = deoarece aceste doar returna o adresa catre
		// obiectul respectiv. Odata iesit din for scoada se stergea automat din memorie
		// si odata cu el si salvarea pe care doream sa o am permanent
	}
	
}

Coada_de_caractere *readAndSaveNQueue(unsigned int &n)
{
	std::cout<<"Cate cozi doriti sa cititi? ";
	std::cin>>n;
	Coada_de_caractere *cozi = new Coada_de_caractere[n];
	for(int i = 0; i<n; i++)
		std::cin>>cozi[i];
		
	std::cout<<"S-au citit urmatoarele cozi: "<<std::endl;
	showQueues(cozi, n);
	
	
	return cozi;
}

void readAndExecuteInput(Coada_de_caractere *q, unsigned int &n)
{
	unsigned int r;
	std::cin>>r;
	
	unsigned int exitcode = 6;
	
	if(r == exitcode)
	return;
	else
	if(r == 1)
	q = readAndSaveNQueue(n);
	else
	if(r == 2)
	demoQueues();
	else
	if(r == 3)
	showQueues(q, n);
	
	
	menu();
	readAndExecuteInput(q, n);
	delete []q;
}



int main()
{
	
	Coada_de_caractere *q = NULL;
	unsigned int n = 0;
	menu();
	readAndExecuteInput(q, n);
	
	
	
	
	

	
    return 0;
}