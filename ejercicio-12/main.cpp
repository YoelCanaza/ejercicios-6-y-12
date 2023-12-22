#include <iostream>
#include <string>

using namespace std;

class Carta {
public:
    Carta() : valor_(""), palo_(""), mazo_("") {}  // Constructor predeterminado
    Carta(string valor, string palo, string mazo) : valor_(valor), palo_(palo), mazo_(mazo) {}

    friend ostream& operator<<(ostream& os, const Carta& carta) {
        os << "Carta: " << carta.valor_ << " de " << carta.palo_ << " en el mazo " << carta.mazo_;
        return os;
    }

private:
    string valor_;
    string palo_;
    string mazo_;
};

class Mazo {
public:
    Mazo() : numCartas_(0) {}  // Constructor predeterminado

    void agregarCarta(Carta carta) {
        cartas_[numCartas_] = carta;
        ++numCartas_;
    }

    friend ostream& operator<<(ostream& os, const Mazo& mazo) {
        os << "Mazo con " << mazo.numCartas_ << " cartas";
        return os;
    }

    Carta& obtenerCarta(int indice) {
        return cartas_[indice];
    }

private:
    static const int capacidadMaxima = 100;  // Capacidad máxima del mazo
    Carta cartas_[capacidadMaxima];
    int numCartas_;
};

template <typename T>
void Intercambio(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    Mazo Mazo1;
    Mazo Mazo2;

    Carta As1("As", "Corazones", "Mazo1");
    Carta As2("As", "Treboles", "Mazo2");

    Mazo1.agregarCarta(As1);
    Mazo2.agregarCarta(As2);

    cout << "Antes del intercambio: " << endl;
    cout << As1 << endl;
    cout << As2 << endl;

    Intercambio(As1, As2);

    cout << "Después del intercambio: " << endl;
    cout << As1 << endl;
    cout << As2 << endl;

    return 0;
}
