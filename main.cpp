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

        friend std::ostream& operator<<(std::ostream &out, const Coada_de_caractere &coada);
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

std::ostream& operator<<(std::ostream &out, const Coada_de_caractere &coada)
{
    Nod *cursour = coada.first;
    while(cursour != NULL)
    {
        out<<cursour->GetInfo()<<" ";
        Nod *next_position = cursour->GetNext();
		delete cursour;
		cursour = next_position;
    }
    return out;
}

std::istream& operator>>(std::istream &in, Coada_de_caractere &coada)
{
	int n;
	std::cout<<"How many charactes would you like to read?\n";
	std::cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		char c;
		std::cout<<"Please enter a charater:";
		in>>c;
		coada.push(c);
	}
    return in;
}



int main()
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
	
	std::cout<<"First queue: ";
	std::cout<<coada<<std::endl;
	std::cout<<"Second queue: ";
	std::cout<<coada2<<std::endl;

    return 0;
}