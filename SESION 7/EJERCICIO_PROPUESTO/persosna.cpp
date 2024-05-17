#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    float salario;

    Persona(string _nombre, int _edad, float _salario, string _correo)
        : nombre(_nombre), edad(_edad), salario(_salario), correo(_correo) {}
    protected:
        string correo;
        virtual void setCorreo(string _correo)=0;
        virtual string getCorreo()=0;
};

class Empleado : protected Persona {
public:
    string departamento;

    Empleado(string _nombre, int _edad, float _salario, string _correo, string _departamento)
        : Persona(_nombre, _edad, _salario, _correo) {
        departamento = _departamento;
    }
    void setCorreo(string _correo)
    {
        correo = _correo;
    }
    string getCorreo()
    {
        return correo;
    }
};

class Cliente : protected Persona {
public:
    string id_cliente;

    Cliente(string _nombre, int _edad, float _salario, string _correo, string _id_cliente)
        : Persona(_nombre, _edad, _salario, _correo) {
            id_cliente = _id_cliente;
    }
    void setCorreo(string _correo)
    {
        correo = _correo;
    }
    string getCorreo()
    {
        return correo;
    }
};

int main() {
    Empleado emp("John Doe", 30, 5000.0, "johndoe@example.com", "Ventas");
    cout << "Correo del Empleado: " << emp.getCorreo() << endl;

    Cliente cli("Jane Doe", 25, 60000, "janedoe@example.com", "1234343");
    cout << "Correo del Cliente: " << cli.getCorreo() << endl;

    return 0;
}
