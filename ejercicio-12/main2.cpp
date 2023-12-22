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

    // Método para cambiar el mazo de la carta
    void cambiarMazo(string nuevoMazo) {
        mazo_ = nuevoMazo;
    }

private:
    string valor_;
    string palo_;
    string mazo_;
};

class Mazo {
public:
    Mazo() : numCartas_(0) {}  // Constructor predeterminado

    void agregarCarta(Carta* carta) {
        if (numCartas_ < capacidadMaxima) {
            cartas_[numCartas_] = carta;
            ++numCartas_;
        } else {
            cout << "Error: El mazo está lleno, no se puede agregar más cartas." << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Mazo& mazo) {
        os << "Mazo con " << mazo.numCartas_ << " cartas";
        return os;
    }

    // Método para intercambiar cartas entre dos mazos
    void intercambiarCartas(Mazo& otroMazo, int indiceCartaEnEsteMazo, int indiceCartaEnOtroMazo) {
        if (indiceCartaEnEsteMazo >= 0 && indiceCartaEnEsteMazo < numCartas_ &&
            indiceCartaEnOtroMazo >= 0 && indiceCartaEnOtroMazo < otroMazo.numCartas_) {

            // Cambiar el mazo de las cartas en ambos mazos
            cartas_[indiceCartaEnEsteMazo]->cambiarMazo(otroMazo.cartas_[indiceCartaEnOtroMazo]->mazo_);
            otroMazo.cartas_[indiceCartaEnOtroMazo]->cambiarMazo(mazo_);

            // Intercambiar las referencias a las cartas entre los mazos
            swap(cartas_[indiceCartaEnEsteMazo], otroMazo.cartas_[indiceCartaEnOtroMazo]);
        } else {
            // Manejar el caso de un índice fuera de rango
            cerr << "Error: Índice fuera de rango." << endl;
        }
    }

private:
    static const int capacidadMaxima = 100;  // Capacidad máxima del mazo
    Carta* cartas_[capacidadMaxima];
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

    Mazo1.agregarCarta(&As1);
    Mazo2.agregarCarta(&As2);

    cout << "Antes del intercambio: " << endl;
    cout << As1 << endl;
    cout << As2 << endl;

    // Intercambiar las cartas entre los mazos
    Mazo1.intercambiarCartas(Mazo2, 0, 0);

    cout << "Después del intercambio: " << endl;
    cout << As1 << endl;
    cout << As2 << endl;

    return 0;
}
