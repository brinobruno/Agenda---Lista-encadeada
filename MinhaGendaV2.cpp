#include <iostream>
#include <algorithm>
#include <conio.h>
#include <locale.h>
#include <string.h>

using namespace std;

typedef struct Contact {
	string name;
	string phoneNum; // because of region code
	string email;
} Contact;

typedef struct Node {
	Contact *friends; //friend
	Node *next;
	Node *before;
} Node;

typedef struct List {
	Node *beginning, *end;
	int size;
} List;

int menu() {
	int option;
	
	do {
		cout <<  "\n\t\tMinhaGenda" << endl;
		cout << "\n\t1 - Mostrar meus contatos (começando pelos +antigos)" << endl;
		cout << "\t2 - Mostrar meus contatos (começando pelos +recentes)" << endl;
		cout << "\t3 - Adicionar contato" << endl;
		cout << "\t4 - Remover meus contatos" << endl;
		cout << "\t5 - Sair\n" << endl;
		
		cout << "O que deseja fazer? Digite o número e aperte enter\n" << endl;
		cin >> option;
		
		if (option < 1 || option > 6)
			cout << "\nComando inválido, tente novamente..." << endl;
			
	}while (option < 1 || option > 5);
	
	return option;
}

bool isEmpty (List *lista) {
	if (lista -> beginning == NULL)
		return true;
	else
	return false;
}

void registry (List *lista, string name, string phoneNum, string email) {
	
	Contact *new1 = new Contact();
	new1->name = name;
	new1->phoneNum = phoneNum;
	new1->email = email;
	
	Node *new2 = new Node();
	new2->friends = new1; //friend
	new2->next = NULL;
	new2->before = NULL;
	
	if (isEmpty(lista))
	{
		lista->beginning = new2;
		lista->end = new2;
	}	
	else
	{
	
		Node *helper = lista->end;
		lista->end->next = new2;
		new2->before = helper;
		lista->end = new2;
}
		lista->size++;
}

void print (List *lista) 

{
	if (isEmpty(lista))
	{
		cout << "\nVocê nao possui contatos registrados na SuaGenda\n";
		cout << "que tal adicionar?\n\n";
	}
	else
	{
		Node* helper = lista->beginning;
		
		cout << "\n	Meus contatos:\n";
		cout << endl << endl << "Nome\t\tTelefone\t\te-mail" << endl;
		
		while(helper != NULL)
		{
			cout << helper->friends->name << "\t\t" << helper->friends->phoneNum << "\t\t" << helper->friends->email << endl << endl;
			
			helper = helper->next;
		}
		cout << endl << endl;
	}
	
	cout << endl << "\nNúmero de contatos: \n" << lista->size << endl;

}

void printBackwards (List *lista) 

{
	if (isEmpty(lista))
	{
		cout << "\nVocê nao possui contatos registrados na SuaGenda\n";
		cout << "que tal adicionar?\n\n";
	}
	else
	{
		Node* helper = lista->end;
		
		cout << "\n	Meus contatos:\n";
		cout << endl << endl << "Nome\t\tTelefone\t\te-mail" << endl;
		
		while(helper != NULL)
		{
			cout << helper->friends->name << "\t\t" << helper->friends->phoneNum << "\t\t" << helper->friends->email << endl << endl;
			
			helper = helper->before;
		}
		cout << endl << endl;
	}
	
	cout << endl << "\nNúmero de contatos: \n" << lista->size << endl;

}

void deletelist(Node** ref)

{
	
	Node* current = *ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        
        free(current);
        
        current = next;
        
    } *ref = NULL;
    
}

int main ()
{
	
	setlocale(LC_ALL,"Portuguese");
	
	List lista;
	
	lista.beginning = NULL;
	lista.end = NULL;
	lista.size = 0;
	
	int choice;
	
	string name, phoneNum, email;
	
	do{
		choice = menu ();
		
		switch(choice)
		{
			case 1:
			print (&lista);
			break;
			
			case 2: 
			printBackwards (&lista);
			break;
			
			case 3:
				cout << "\n\tDigite o nome: ";
				_flushall();
				getline(cin, name);
				
				cout << "\t\tDigite o número de telefone: ";
				_flushall();
				getline(cin, phoneNum);
				
				cout << "\t\tDigite o endereço de e-mail: ";
				_flushall();
				getline(cin, email);
				
				registry (&lista, name, phoneNum, email);
			break;
			
			case 4:
				cout << "\nDeletando lista..." << endl;
				deletelist(&lista.beginning);
				break;
			
			default:
				cout << "\nVocê saiu da MinhaGenda" << endl;	
		}
		
	}while(choice != 5);
	
	getch();
	return 0;
}











