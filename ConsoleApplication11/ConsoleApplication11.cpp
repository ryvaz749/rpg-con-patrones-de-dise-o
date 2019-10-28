/*
falta:
cambiar clases de personajes.
logros.
storylines.
guardar y cargar.
equipamento de monos.
listas.
constructor copia
templates.
delegar constructores.
patrones de diceño:
	facade
	adapter
	bridge
	factory
	decorator
	singleton 
	double checked loking

*/



#include "pch.h"
#include <iostream>
#include <list>
#include <stdlib.h>
#include "enemy.h"
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <fstream>
#include"arma.h"
#include "curador.h"
#include <set>
#include "party.h"
class ranger;
#include "ranger.h"
class mago;
#include "mago.h"
class brujo;
#include "brujo.h"
class chaman;
#include "chaman.h"
class driuda;
#include "driuda.h"
class hechisero;
#include "hechisero.h"
class paladin;
#include "paladin.h"
class priest;
#include "priest.h"
class rogue;

#include "rogue.h"
using namespace std;
void ganarexp(vector<personaje*>* pary, int exp) {
	system("cls");
	cout << "ganaste "<<exp<<"exp"<<endl;
	for (int a = 0; a < pary->size(); a++) {
		(*pary)[a]->exp += exp /pary->size();
		(*pary)[a]->cansado = true;
		cout << (*pary)[a]->name << ": ahora tiene " << (*pary)[a]->exp << "xp"<<endl;
		if ((*pary)[a]->exp > ((*pary)[a]->nivel + 3) ^ 2) {
			(*pary)[a]->nivel += 1;
			exp = 0;
			cout << (*pary)[a]->name << ": ahora es nivel " << (*pary)[a]->nivel << endl;
		}
	}
}
void render(vector<personaje*>* pary) {
	system("cls");
	cout << "pary: " << endl;
	for (int a = 0; a < pary->size(); a++) {
		cout << a + 1 << (*pary)[a]->name << " " << (*pary)[a]->clase << " " << (*pary)[a]->vida << "hp" << " " << endl;
	}
}
void render(vector<enemy> enemys, vector<personaje*>* pary) {
	render(pary);
	cout << "enemys: ";
	for (int a = 0; a < enemys.size(); a++) {
		cout << a + 1 + pary->size() << enemys[a].name << " " << enemys[a].vida << "ph " << endl;
	}
	
}

void encuentro(vector<enemy*> enemys, vector<personaje*>* pary) {
	system("cls");
	int cuantos = rand() % 3 + 1;
	if (enemys.size() == 1) {
		cuantos = 1;
	}
	enemy enemigo = *enemys[rand() % 4];
	vector<enemy> este;
	int cual = 0;
	cout << "te has encontrado con " << cuantos << " " << enemigo.name;
	if (cuantos != 1) {
		cout << "s";
	}
	cout << endl;
	cout << "0-escapar"<<endl;
	cin >> cual;
	if (cual == 0) {
		return;
	}
	system("pause");
	for (int a = 0; a < cuantos; a++) {
		este.push_back(enemigo);
	}
	while (pary->size() > 0 && este.size()>0) {
		for (int a = 0; a < pary->size(); a++) {
			render(este, pary);
			(*pary)[a]->atak(&este,pary);
			if (este.size() == 0) {
				if (este.size() == 1) {
					cout << "ganaste";
					system("exit");
				}
				ganarexp(pary, enemigo.exp*cuantos);
				break;
			}
		}
		cout << endl;
		for (int a = 0; a < este.size(); a++) {
			render(este, pary);
			cual = rand() % pary->size();
			este[a].atak(&este,pary);
			
			if ((*pary)[cual]->vida <= 0) {
				delete (*pary)[cual];
				pary->erase(pary->begin() + cual);
			}
			if (pary->size() <= 0) {
				cout << "telapelaste";
				system("exit");
			}
		}
		cout<<endl;
	}
	
}
void nombres(vector<enemy*>* li,vector<string> nombres,vector<int> vidas, vector<int> atakes,vector<int> exp) {
	for (int a = 0; a < nombres.size(); a++) {
		li->push_back(new enemy());
		(*li)[a]->name = nombres[a];
		(*li)[a]->vida = vidas[a];
		(*li)[a]->atake = atakes[a];
		(*li)[a]->exp = exp[a];
	}

}
int experiencia(vector<personaje*>* pary) {
	int e = 0;
	for (int a = 0; a < pary->size(); a++) {
		e += (*pary)[a]->exp;
	}
	return e;
}
void taberna(vector<personaje*>* pary,string clases[9],string nombres[11]) {
	int cual,e;
	string cuale;
	map<string, string>::iterator i;
	while (true) {
		system("cls");
		map<string,string> personas;
		for (int a = 0; a < 4; a++) {
			personas.insert(pair<string, string>((nombres)[rand() % 11], (clases)[rand() % 9]));
		}
		cout << "has llegado a la taberna, aqui podras despedir y contratar nuevos personajes para tu pary; 1-despedir, 2-contratar 3-salir"<<endl;
		cin >> cual;
		if (cual == 3) {
			break;
		}
		else if (cual == 1) {
			if (pary->size() == 1) {
				cout << "tu pary sta casi vacia" << endl;
			}
			else{
				render({}, pary);
				cout << " 0-cancelar"<<endl << "a quien quieres despedir: ";
				cin >> cual;
				if (cual == 0) {
					continue;
				}
				cual -= 1;
				delete (*pary)[cual];
				pary->erase(pary->begin() + cual);
			}
			
		}
		else if (cual == 2) {
			if (pary->size() == 4) {
				cout << "tu pary sta llena" << endl;
			}
			else {
				for (map<string, string>::iterator a = personas.begin(); a != personas.end(); a++) {
					cout << a->first << " " << a->second << endl;
				}
				cout << "a quien quieres contratar: ";
				cin >> cuale;
				pary->push_back(new personaje());
				(*pary)[pary->size() - 1]->name = cuale;
				(*pary)[pary->size() - 1]->clase = personas[cuale];
			}
			
		}
	}
	
}
void armar(vector<arma*>* tienda,string clases[9], vector<string> nombre,vector<int> clase, vector<int> dao, vector<int> durabilidad, vector<int> precio) {
	for (int a = 0; a < nombre.size(); a++) {
		tienda->push_back(new arma(nombre[a], clases[clase[a]], dao[a], durabilidad[a], precio[a]));
	}
	
}
void tiendita(vector<personaje*>* pary, vector<arma*> armas) {
	int dinero = 0;
	map<string, arma> tienda;
	int cual;
	string cuale;
	for (int a = 0; a < 4; a++) {
		cual = rand() % 10;
		tienda.insert(pair<string, arma>(armas[cual]->nombre,(* armas[cual])));
	}
	
	system("cls");
	cout << "has llegado a una tienda"<<endl;
	for (map<string, arma>::iterator a = tienda.begin(); a != tienda.end(); a++) {
		cout << a->first << " " << a->second.precio << endl;
	}
	cout << "0 salir" << endl;
	while (true) {
		cout << "cual quieres comprar: ";
		cin >> cuale;
		if (cuale == "0") {
			break;
		}
		if (dinero < tienda[cuale].precio) {
			cout << "no te alcanza pobre" << endl;
		}
		else {
			dinero -= tienda[cuale].precio;
			render({}, pary);
			cout << "a quien se la equipas: ";
			cin >> cual;
			if ((*pary)[cual]->clase == tienda[cuale].clase) {
				tienda[cuale].dao *= 2;
			}
			(*pary)[cual]->weapon = tienda[cuale];
			(*pary)[cual]->ta = true;
		}
	}
}
void charla(personaje* a, personaje* b) {
	if (a->pareja.second != NULL) {
		a->pareja.second->pareja.second = NULL;
	}
	a->pareja.second = b;
	a->pareja.first = 0;
}
void campamento(vector<personaje*>* pary) {
	int cual,cual0,ya;
	set<personaje*> temporal;
	cout << "1-dormir,2-carnitasada,3-mostrar stats,4-organizarse,5-guardar y salir" << endl;
	cin >> cual;
	switch (cual)
	{
	case 1:
		for (int a = 0; a < pary->size(); a++) {
			if ((*pary)[a]->cansado == true) {
				(*pary)[a]->vida += 1;
				(*pary)[a]->cansado = false;
			}
		}
		break;
	case 2:
		while (true) {
			render({}, pary);
			cout << "quienes van a hablar";
			cin >> cual;
			cin >> cual0;
			if (cual == cual0) {
				cout << (*pary)[cual]->name << " esta hablando solo";
				continue;
			}
			if ((*pary)[cual]->pareja.second == (*pary)[cual0]) {
				(*pary)[cual]->pareja.first += 1;
				(*pary)[cual0]->pareja.first += 1;
			}
			else {
				charla((*pary)[cual], (*pary)[cual0]);
				charla((*pary)[cual0], (*pary)[cual]);
			}
		}
	case 3:
		for (int a = 0; a < pary->size(); a++) {
			cout << (*pary)[a]->name <<" "<< (*pary)[a]->clase<<endl;
			cout << "vida: " << (*pary)[a]->vida <<"/"<< (*pary)[a]->vidamaxima<< endl;
			cout << "atake: " << ((*pary)[a]->atake + (*pary)[a]->weapon.dao) << endl;
			cout << "nivel: " << (*pary)[a]->nivel;
			cout << "exp: " << (*pary)[a]->exp<< "/" << (((*pary)[a]->nivel + 3) ^ 2);
			cout << "arma: " << (*pary)[a]->weapon.nombre << " +" << (*pary)[a]->weapon.dao;

		}
		break;
	case 4:
		render(pary);
		cout << "reacomoda el orden de ultimo a primero" << endl;
		while (temporal.size() != pary->size()) {
			cin >> cual;
			temporal.insert((*pary)[cual - 1]);
		}
		cual = 0;
		for (set<personaje*>::iterator it = temporal.begin(); it != temporal.end(); it++,cual++) {
			(*pary)[cual] = (*it);
		}
		break;
	//case 3:

	default:
		break;
	}
}

void colocar(vector<vector<char>>* mapa, vector<char> lugares) {
	int x = 0, y = 0;
	for (int a = 0; a < lugares.size(); a++) {
		x = rand() % 5;
		y = rand() % 5;
		while ((*mapa)[x][y] != 'd') {
			x = rand() % 5;
			y = rand() % 5;
		}
		(*mapa)[x][y] = lugares[a];
	}
}
int main()
{
	
	srand(time(NULL));
	int cual;
	party pary;
	vector<enemy*> enemys;
	vector<vector<char>> mapa;
	vector<arma*> tienda;
	ranger prueba;
	string names[11] = { "polin","hietrianz","morbert","juster","seber","matt","davelian","gottmuno","diebas","manutholf","burens" };
	mapa.resize(5);
	for (int a = 0; a < 5; a++) {
		mapa[a].resize(5);
		for (int e = 0; e < 5; e++) {
			mapa[a][e] = 'd';
		}
	}
	int continuar = 0;
	int direccion,x=0,y=0;
	string clases[9] = { "warrior","hunter","rogue","paladin","mago","shaman","brujo","druida","chaman" };
	colocar(&mapa, { 'p','t','b','q','w' });
	nombres(&enemys, { "momia","devilsaur","bandido","tigre","wyrm","demonio","imp","treant","golem" }, { 1,1,1,1,1,1,1,1,1 }, { 1,1,1,1,1,1,1,1,1 }, { 1,1,1,1,1,1,1,1,1 });
	armar(&tienda,clases, { "battle-axe","war-axe","heavy-axe","bow","longbow","poison dagger","assasins-blade","sword","blade","hammer"}, { 1,1,1,2,2,3,3,4,4,6 }, { 2,3,1,3,7,2,3,5,2,2 }, { 2,2,3,2,2,2,4,3,2,8 }, {13, 39, 13,39,91,13,65,65,26,65});
	cout<<"crea tu pary"<<endl;
	cout << "1-ranger 2-mago 3-hechisero 4-brujo 5-paladin 6-rouge 7-priest 8-druida 9-chaman"<<endl;
	for (int a = 1; a < 5; a++) {
		cout << "personaje " << a << endl;
		cout << "clase: ";
		cin >> cual;
		switch (cual) {
		case 1:
			pary.push_back(new ranger());
			break;
		case 2:
			pary.push_back(new mago());
			break;
		case 3:
			pary.push_back(new hechisero());
			break;
		case 4:
			pary.push_back(new brujo());
			break;
		case 5:
			pary.push_back(new paladin());
			break;
		case 6:
			pary.push_back(new rogue());
			break;
		case 7:
			pary.push_back(new priest());
			break;
		case 8:
			pary.push_back(new driuda());
			break;
		case 9:
			pary.push_back(new chaman());
			break;
		}
		
		(*pary.rbegin())->clase = clases[cual];
		cout << "nombre: ";
		cin >> (*pary.rbegin())->name;
		
	}
	while (true) {
		cout << "hacia donde quieres ir: 1-adelante,2-atras,3-derecha,4-izquierda,0-acampar"<<endl;
		cin >> direccion;
		if (direccion == 0) {
			campamento(&pary);
			continue;
		}
		switch (direccion)
		{
		case 1:
			x = (x + 1) % 5;
			break;
		case 2:
			x = (x + 4) % 5;
			break;
		case 3:
			y = (y + 1) % 5;
			break;
		case 4:
			y = (y + 4) % 5;
			break;
		default:
			break;
		}
		encuentro(enemys, &pary);

		switch (mapa[x][y])
		{
		case 'd':
			pary.ayardinero();
			mapa[x][y] = ' ';
			break;
		case 'p':
			taberna(&pary, clases, names);
			break;
		case 't':
			tiendita(&pary, tienda);
		case 'b':
			if (experiencia(&pary) < 100) {
				"has llegado a lo que parese un antiguo altar";
			}
			else {
				encuentro({ enemys[5] }, &pary);
			}
			break;
		default:
			break;
		}
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
