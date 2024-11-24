#include <iostream>
using namespace std;

struct Punto {
    int x, y;
};

int productoCruzado(const Punto& p1, const Punto& p2, const Punto& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool puntoEnSegmento(const Punto& p, const Punto& a, const Punto& b) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int verificarInterseccion(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4) {
    int o1 = productoCruzado(p1, p2, p3);
    int o2 = productoCruzado(p1, p2, p4);
    int o3 = productoCruzado(p3, p4, p1);
    int o4 = productoCruzado(p3, p4, p2);

    if ((o1 * o2 < 0) && (o3 * o4 < 0)) {
        return 1;
    }

    if (o1 == 0 && puntoEnSegmento(p3, p1, p2)) return 1;
    if (o2 == 0 && puntoEnSegmento(p4, p1, p2)) return 1;
    if (o3 == 0 && puntoEnSegmento(p1, p3, p4)) return 1;
    if (o4 == 0 && puntoEnSegmento(p2, p3, p4)) return 1;

    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) return 0;

    return -1;
}

int main() {
    Punto p1, p2, p3, p4;

    cout << "Ingrese las coordenadas del primer segmento (x1 y1 x2 y2): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cout << "Ingrese las coordenadas del segundo segmento (x3 y3 x4 y4): ";
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    int resultado = verificarInterseccion(p1, p2, p3, p4);

    if (resultado == 1)
        cout << "Las lineas se cruzan." << endl;
    else if (resultado == 0)
        cout << "Las lineas son paralelas." << endl;
    else
        cout << "Las lineas no se cruzan ni son paralelas." << endl;

    return 0;
}
