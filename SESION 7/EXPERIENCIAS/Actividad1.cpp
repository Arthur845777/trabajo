#include <iostream>
#include <string>
using namespace std;
class Cliente {
protected:
    string nombre;
    string direccion;
    string telefono;
    string email;
    string numeroTarjeta;
    string codigoSeguridad;
public:
    Cliente(string n, string d, string t, string e, string nt, string cs) : nombre(n), direccion(d), telefono(t), email(e), numeroTarjeta(nt), codigoSeguridad(cs) {}
    string getNombre() { return nombre; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    string getEmail() { return email; }
    string getNumeroTarjeta() { return numeroTarjeta; }
    string getCodigoSeguridad() { return codigoSeguridad; }
};
class ClienteSeguro : public Cliente {
private:
    string encriptar(string data) {
        string encrypted = data;
        char key = 'K';
        for (size_t i = 0; i < data.size(); ++i) {
            encrypted[i] ^= key;
        }
        return encrypted;
    }
    string desencriptar(string data) {
        return encriptar(data);
    }
public:
    ClienteSeguro(string n, string d, string t, string e, string nt, string cs) : Cliente(n, d, t, e, nt, cs) {}
    string getTarjetaEncriptada() {
        return encriptar(numeroTarjeta);
    }
    string getCodigoSeguridadEncriptado() {
        return encriptar(codigoSeguridad);
    }
    bool verificarAutenticidad(string nombre, string codigo) {
        return (this->nombre == nombre && this->codigoSeguridad == codigo);
    }
};
int main() {
    ClienteSeguro cliente("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "1234567890123456", "123");
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Tarjeta Encriptada: " << cliente.getTarjetaEncriptada() << endl;
    cout << "Codigo Seguridad Encriptado: " << cliente.getCodigoSeguridadEncriptado() << endl;
    if (cliente.verificarAutenticidad("Alexander", "123")) {
        cout << "Autenticidad verificada." << endl;
    } else {
        cout << "Autenticidad no verificada." << endl;
    }
    return 0;
}
