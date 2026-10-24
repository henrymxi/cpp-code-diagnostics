#include <iostream>
#include <iomanip>
#include <locale>
#include <vector>
using namespace std;

struct Candidatos{
    string Nombre, PartidoPolitico;
    int EdadCandidato;
    int VotosTelevision, VotosRadio, VotosInternet, CostoCampaña;
    float PorcentajeVotos, VotosTotales;

    void InformacionCandidato();
    void Votar(int medio);
    void CalcularVotosTotales();
    void CalcularCostoCampaña();
    void VaciarUrna();
    void CalcualrPorcentajeVotos(float TodosVotos);
};

struct Votante{
    string Genero;
    int EdadVotante;
};

void Candidatos::InformacionCandidato(){
    cout<<"\nEste es nuestro candidato "<<Nombre<<", el cual tiene "<<EdadCandidato<<" años, y pertenece al partido político "<<PartidoPolitico
        <<".\nObtuvo una cantidad de "<<VotosTotales<<" votos, de los cuales fueron:"
        <<"\n 1. " <<VotosTelevision<< " de televisión."
        <<"\n 2. " <<VotosRadio<< " de radio."
        <<"\n 3. " <<VotosInternet<< " de internet.\n"
        <<"Por lo tanto, su campaña costó: "<<CostoCampaña<<" pesos.\n\n";
    cout<<"Porcentaje General de Votos: " << fixed << setprecision(2) << PorcentajeVotos << " %\n\n" << fixed << setprecision(0);
}

void Candidatos::CalcularVotosTotales(){
    VotosTotales = VotosTelevision + VotosRadio + VotosInternet;
}

void Candidatos::CalcualrPorcentajeVotos(float TodosVotos){
    if (TodosVotos>0)
        PorcentajeVotos = VotosTotales / TodosVotos *100;
    else
        PorcentajeVotos = 0;
}

void Candidatos::CalcularCostoCampaña(){
    CostoCampaña = VotosTelevision * 1000 + VotosRadio * 500 + VotosInternet * 100;
}

void Candidatos::Votar(int medio){
    switch (medio)
    {
        case 1: VotosTelevision++; break;
        case 2: VotosRadio++; break;
        case 3: VotosInternet++; break;
    }
    cout<<"\n¡Voto registrado con éxito!\n\n";
    CalcularVotosTotales();
    CalcularCostoCampaña();
}

void Candidatos::VaciarUrna(){
    VotosTelevision = VotosRadio = VotosInternet = VotosTotales = 0;
    CalcularVotosTotales();
    CalcularCostoCampaña();
}

bool VolverAlMenu(){
    char opcion;
    cout<<"¿Desea regresar al menú? (s/n): ";
    cin>>opcion;
    return (opcion == 's' || opcion == 'S');
}

int main(){
//PORTADA
     cout<<"=============================================\n"
         <<"        SISTEMA DE INFORMACIÓN ELECTORAL\n"
         <<"=============================================\n"
         <<"Autores del programa:\n"
         <<" - Bryan Manuel Tarra Hernández\n"
         <<" - Johan Sneider Vega Ibarra\n"
         <<"=============================================\n"
         <<"Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
    system("clear"); //en vez cls, se usa cleral, porque OnlineGDB usa Linux no Windows
//

    cout<<fixed<<setprecision(0);
    cout.imbue(locale(""));

    Candidatos Informacion[3];
    Informacion[0].Nombre = "Juan Carlos Vega Tarra"; 
    Informacion[0].EdadCandidato = 30;
    Informacion[0].PartidoPolitico = "Liberal";
    Informacion[0].VotosTelevision = 7;
    Informacion[0].VotosRadio = 8;
    Informacion[0].VotosInternet = 9;
    Informacion[0].CalcularVotosTotales();
    Informacion[0].CalcularCostoCampaña();

    Informacion[1].Nombre = "Mely Angelina Vanegas Florez";
    Informacion[1].EdadCandidato = 31;
    Informacion[1].PartidoPolitico = "Conservador";
    Informacion[1].VotosTelevision = 4;
    Informacion[1].VotosRadio = 5;
    Informacion[1].VotosInternet = 6;
    Informacion[1].CalcularVotosTotales();
    Informacion[1].CalcularCostoCampaña();

    Informacion[2].Nombre = "Fernando Fernandez Mejia Londoño";
    Informacion[2].EdadCandidato = 32;
    Informacion[2].PartidoPolitico = "Cambio Radical";
    Informacion[2].VotosTelevision = 1;
    Informacion[2].VotosRadio = 2;
    Informacion[2].VotosInternet = 3;
    Informacion[2].CalcularVotosTotales();
    Informacion[2].CalcularCostoCampaña();

    vector<Votante> ListaVotante;

    int opcion;
    string idCandidato;
    char confirmar;

    do{

        cout<<"APLICACIÓN PARA EL MANEJO DE INFORMACIÓN ELECTORAL"
         <<"\nAquí está nuestra App que le ayudará a saber e interactuar con nuestros candidatos. Estas son las siguientes opciones: "
         <<"\n1) Visualizar la información de un candidato."
         <<"\n2) Votar por un candidato."
         <<"\n3) Calcular el número total de votos."
         <<"\n4) Calcular el costo promedio por campaña."
         <<"\n5) Visualizar las estadísticas por rango de edad y género."
         <<"\n6) Vaciar la urna."
         <<"\nEscoja un número según la opción que necesite: ";
        cin>>opcion;

        if (opcion < 1 or opcion > 6){
            cout<<"\nOpción no válida. Debe escoger un número entre 1 y 6.\n\n";
            if (!VolverAlMenu()) exit(0);
            continue;  
        }

    switch (opcion){

        case 1:{
            int acum=0;
            for (int x=0; x<3; x++){
                Informacion[x].CalcularVotosTotales();
                acum += Informacion[x].VotosTotales;
            }
            for (int x=0; x<3; x++){
                Informacion[x].CalcualrPorcentajeVotos(acum);
            }

            cout<<"\nEstas son nuestras opciones:"
                <<"\n1. Los tres candidatos."
                <<"\n2. Juan Carlos Vega Tarra."
                <<"\n3. Mely Angelina Vanegas Florez."
                <<"\n4. Fernando Fernandez Mejia Londoño."
                <<"\nEscoja un número según la opción que necesite: ";
            cin>>idCandidato;

            if (idCandidato=="1"){
                for (int x = 0; x < 3; x++){
                    cout << "\nCANDIDATO " << x+1 << ":";
                    Informacion[x].InformacionCandidato();
                }
            }
            else if (idCandidato=="2"){
                Informacion[0].InformacionCandidato();
            }
            else if (idCandidato=="3"){
                Informacion[1].InformacionCandidato();
            }
            else if (idCandidato=="4"){
                Informacion[2].InformacionCandidato();
            }
            else{
                cout<<"Opción no válida. Debe escoger un número entre 1 y 4.\n\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }

            if (!VolverAlMenu()) exit(0);
        }break;

        case 2: {
            int InfluenciaVoto, OpcionCandidato;
            Votante NuevoVotante;
        
            cout<<"\nEstos son nuestros tres candidatos:"
                <<"\n1) Juan Carlos Vega Tarra."
                <<"\n2) Mely Angelina Vanegas Florez."
                <<"\n3) Fernando Fernandez Mejia Londoño."
                <<"\nEscoja un número según el candidato por el cual vaya a votar: ";
            cin>>OpcionCandidato;
        
            if (OpcionCandidato < 1 or OpcionCandidato > 3){
                cout<<"\nOpción no válida. Debe escoger un número entre 1 y 3.\n\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }
        
            int indice = OpcionCandidato - 1;
        
            cout<<"\n¿Por dónde se enteró del candidato?"
                <<"\n1) Televisión."
                <<"\n2) Radio."
                <<"\n3) Internet."
                <<"\nEscoja un número: ";
            cin>>InfluenciaVoto;
        
            if (InfluenciaVoto < 1 or InfluenciaVoto > 3){
                cout<<"\nOpción no válida. Debe escoger un número entre 1 y 3.\n\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }
        
            string edad;
            cout << "\nIngrese su edad: ";
            cin >> edad;
        
            bool edadValida = true;
            for (char c : edad) {
                if (!isdigit(c)) {
                    cout << "\nEdad no válida.\n\n";
                    if (!VolverAlMenu()) exit(0);
                    edadValida = false;
                    break;
                }
            }
        
            if (!edadValida) break;
        
            NuevoVotante.EdadVotante = stoi(edad);
        
            if (NuevoVotante.EdadVotante < 18 and NuevoVotante.EdadVotante > 0) {
                cout << "\nUsted es menor de edad, su voto no es válido.\n\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }
            if (NuevoVotante.EdadVotante > 116 or NuevoVotante.EdadVotante <= 0) {
                cout << "\nEdad no válida.\n\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }
        
            cout<<"\nIndique su género: "
                <<"\n1) Masculino"
                <<"\n2) Femenino"
                <<"\n3) Otro"
                <<"\nIngrese el número: ";
            string OpcionGenero;
            cin>>OpcionGenero;
        
            if (OpcionGenero=="1") NuevoVotante.Genero = "Masculino";
            else if (OpcionGenero=="2") NuevoVotante.Genero = "Femenino";
            else if (OpcionGenero=="3") NuevoVotante.Genero = "Otro";
            else{
                cout<<"\nOpción no válida.\n\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }
        
            ListaVotante.push_back(NuevoVotante);
            Informacion[indice].Votar(InfluenciaVoto);
        
            cout << Informacion[indice].Nombre << " ahora tiene "
                 << Informacion[indice].VotosTotales << " votos totales.\n"
                 << "Costo de campaña actual: "
                 << Informacion[indice].CostoCampaña << " pesos.\n\n";
        
            if (!VolverAlMenu()) exit(0);
        } break;


        case 3:{
            int Acum = 0;
            cout<<"\nVotos totales obtenidos por cada candidato:\n";

            for (int x = 0; x < 3; x++){
                Informacion[x].CalcularVotosTotales();
                cout<<x+1<<". "<<Informacion[x].Nombre<<" obtuvo "<<Informacion[x].VotosTotales<<" votos.\n";
                Acum += Informacion[x].VotosTotales;
            }
            cout<<"\nTotal de votos entre todos los candidatos: "<<Acum<<".\n";

            if (!VolverAlMenu()) exit(0);
        } break;

        case 4:{
            int Acum = 0;
            cout<<"\nCosto por campaña:\n";

            for (int x = 0; x < 3; x++){
                Informacion[x].CalcularCostoCampaña();
                cout<<x+1<<". "<<Informacion[x].Nombre<<" costó "<<Informacion[x].CostoCampaña<<" pesos.\n";
                Acum += Informacion[x].CostoCampaña;
            }
            cout<<"\nCosto promedio: "<<Acum/3<<" pesos.\n";

            if (!VolverAlMenu()) exit(0);
        } break;

        case 5:{
            if (ListaVotante.empty()){
                cout<<"\nNo hay votos registrados.\n";
                if (!VolverAlMenu()) exit(0);
                break;
            }

            float totalVotos = ListaVotante.size();
            float countF=0, countM=0, countO=0;
            float c18_25=0, c26_40=0, c41_60=0, c61mas=0, menores=0;

            for (const auto& v : ListaVotante){
                if (v.Genero=="Femenino") countF++;
                else if (v.Genero=="Masculino") countM++;
                else countO++;

                if (v.EdadVotante < 18) menores++;
                else if (18<=v.EdadVotante && v.EdadVotante<=25) c18_25++;
                else if (26<=v.EdadVotante && v.EdadVotante<=40) c26_40++;
                else if (41<=v.EdadVotante && v.EdadVotante<=60) c41_60++;
                else c61mas++;
            }

            cout<<"\nESTADÍSTICAS DE VOTANTES\n\n";
            cout<<"Total con perfil: "<<totalVotos<<"\n\n";

            cout<<"Género:\n";
            cout<<"Masculino: "<<countM<<" ("<<countM/totalVotos*100<<"%)\n";
            cout<<"Femenino: "<<countF<<" ("<<countF/totalVotos*100<<"%)\n";
            cout<<"Otro: "<<countO<<" ("<<countO/totalVotos*100<<"%)\n\n";

            cout<<"Rango de edad:\n";
            cout<<"Menores de 18: "<<menores<<" ("<<menores/totalVotos*100<<"%)\n";
            cout<<"18-25: "<<c18_25<<" ("<<c18_25/totalVotos*100<<"%)\n";
            cout<<"26-40: "<<c26_40<<" ("<<c26_40/totalVotos*100<<"%)\n";
            cout<<"41-60: "<<c41_60<<" ("<<c41_60/totalVotos*100<<"%)\n";
            cout<<"+60: "<<c61mas<<" ("<<c61mas/totalVotos*100<<"%)\n";

            if (!VolverAlMenu()) exit(0);
        } break;

        case 6:{
            cout<<"\n¿Está seguro de querer vaciar la urna? (s/n): ";
            cin>>confirmar;

            if (confirmar=='s' or confirmar=='S'){
                for (int i=0;i<3;i++) Informacion[i].VaciarUrna();
                cout<<"\nUrnas vaciadas.\n";
            }

            if (!VolverAlMenu()) exit(0);
        } break;

    }

    }while(true);
}
