#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Paciente;
class Medico 
{
private:
    string id;
    string classe;
    map<string, Paciente*> pacientes;

public:
    Medico(string id, string classe) : id(id), classe(classe) {}
    
    string getId() 
    {
        return this->id;
    }

    void addPaciente(Paciente* paciente);
    
    void removerPaciente(string idPaciente);

    vector<Paciente> getPacientes() 
    {
        vector<Paciente> gPacientes;
        for (auto it : pacientes) 
        {
            gPacientes.push_back(*it.second);
        }
        return gPacientes;
    }

    string getClasse() 
    {
        return this->classe;
    }

    friend ostream& operator<<(ostream& os, Medico& medico) 
    {
        os << "Medico: " << medico.id << ":" << medico.classe << " Paciente: [";
        int cont = 0;
        for (auto it : medico.pacientes) 
        {
            cont++;
            os << it.first;
            if(cont != (int) medico.pacientes.size()) {
                os << ",";
            }
        }
        os << "]";
        return os;
    }
};

class Paciente 
{
private:
    string Id;
    string diagnostico;
    map<string, Medico*> medicos;

public:
    Paciente(string Id, string diagnostico) : Id(Id), diagnostico(diagnostico) {}
    
    string getId() 
    {
        return this->Id;
    }

    void addMedico(Medico* medico);
    
    void removerMedico(string idMedico);
    
    vector<Medico> getMedicos() 
    {
        vector<Medico> gMedicos;
        for (auto it : medicos) 
        {
            gMedicos.push_back(*it.second);
        }
        return gMedicos;
    }

    string getDiagnostico() 
    {
        return diagnostico;
    }

    friend ostream& operator<<(ostream& os, Paciente& p) 
    {
        os << "Pac: " << p.Id << ":" << p.diagnostico << " Meds: [";
        int cont = 0;
        for (auto it : p.medicos) 
        {
            cont++;
            os << it.first;
            if(cont != (int) p.medicos.size()) 
            {
                os << ",";
            }
        }
        os << "]";
        return os;
    }
};

void Medico::addPaciente(Paciente* paciente) 
{
    auto key = pacientes.find(paciente->getId());
    if (key == pacientes.end()) 
    {
        this->pacientes[paciente->getId()] = paciente;
    }
}

void Medico::removerPaciente(string idPaciente) 
{
    auto key = pacientes.find(idPaciente);  
    if (key != pacientes.end()) 
    {
        pacientes.erase(key);
    }
}

void Paciente::addMedico(Medico* medico) 
{
    auto key = medicos.find(medico->getId());
        if (key == medicos.end()) 
        {
        this->medicos[medico->getId()] = medico;
        }
}

void Paciente::removerMedico(string idMedico) 
{
    auto key = medicos.find(idMedico);  
        if (key != medicos.end()) 
        {
        medicos.erase(key);
        }
}

class Hospital 
{
private:
    map<string, Paciente*> pacientes;
    map<string, Medico*> medicos;

public: 
    Hospital(){}

    void addPaciente(Paciente* paciente) 
    {
        auto key = pacientes.find(paciente->getId());
        if (key == pacientes.end()) 
        {
            this->pacientes[paciente->getId()] = paciente;
        }
    }

    void addMedico(Medico* medico) 
    {
        auto key = medicos.find(medico->getId());
        if (key == medicos.end()) 
        {
            this->medicos[medico->getId()] = medico;
        }
    }

    void removerPaciente(string idPaciente) 
    {
        auto key = pacientes.find(idPaciente);  
        if (key != pacientes.end()) 
        {
            pacientes.erase(key);
        }
    }

    void removerMedico(string idMedico) 
    {
        auto key = medicos.find(idMedico);  
        if (key != medicos.end()) 
        {
            medicos.erase(key);
        }
    }

    void vincular(string nomeMedico, string nomePaciente) 
    {
        this->medicos[nomeMedico]->addPaciente(this->pacientes[nomePaciente]);
        this->pacientes[nomePaciente]->addMedico(this->medicos[nomeMedico]);
    }

    friend ostream& operator<<(ostream& os, Hospital& h) 
    {
        os << "Medicos:\n";
        for (auto it : h.medicos) {
            os << *it.second << endl;
        }
        os << "\nPacientes:\n";
        for (auto it : h.pacientes) {
            os << *it.second << endl;
        }
        return os;
    }
};

int main() 
{
    Hospital hospital;

    while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "addPac") {
            string id;
            string diagnostico;
            ss >> id >> diagnostico;
            hospital.addPaciente(new Paciente(id, diagnostico));
        } else if (cmd == "remPac") {
            string id;
            ss >> id;
            hospital.removerPaciente(id);
        } else if (cmd == "addMed") {
            string id;
            string classe;
            ss >> id >> classe;
            hospital.addMedico(new Medico(id, classe));
        } else if (cmd == "remMed") {
            string id;
            ss >> id;
            hospital.removerMedico(id);
        } else if (cmd == "vincular") {
            string nomeMedico;
            string nomePaciente;
            ss >> nomeMedico >> nomePaciente;
            hospital.vincular(nomeMedico, nomePaciente);
        } else if (cmd == "show") {
            cout << hospital;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}