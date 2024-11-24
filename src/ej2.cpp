#include <iostream>
using namespace std;

struct Punto {
    int x, y;
};

int verificarRelacion(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4) {
    double pendiente1 = (p2.y - p1.y) / static_cast<double>(p2.x - p1.x);
    double pendiente2 = (p4.y - p3.y) / static_cast<double>(p4.x - p3.x);

    if (pendiente1 == pendiente2) return 0;

    if (pendiente1 * pendiente2 == -1) return 1;

    return -1;
}

int main() {
    Punto p1, p2, p3, p4;

    cout << "Ingrese las coordenadas del primer segmento (x1 y1 x2 y2): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cout << "Ingrese las coordenadas del segundo segmento (x3 y3 x4 y4): ";
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    int resultado = verificarRelacion(p1, p2, p3, p4);

    if (resultado == 1)
        cout << "Las lineas son perpendiculares." << endl;
    else if (resultado == 0)
        cout << "Las lineas son paralelas." << endl;
    else
        cout << "Las lineas se cruzan." << endl;

    return 0;
}
