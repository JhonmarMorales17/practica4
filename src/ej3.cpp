#include <iostream>
#include <cmath> // Para acos, sqrt y pow

using namespace std;

struct Punto {
    double x, y;
};

double calcularAngulo(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4, bool enGrados = false) {
    double dx1 = p2.x - p1.x;
    double dy1 = p2.y - p1.y;

    double dx2 = p4.x - p3.x;
    double dy2 = p4.y - p3.y;

    double productoEscalar = dx1 * dx2 + dy1 * dy2;

    double magnitud1 = sqrt(pow(dx1, 2) + pow(dy1, 2));
    double magnitud2 = sqrt(pow(dx2, 2) + pow(dy2, 2));

    double angulo = acos(productoEscalar / (magnitud1 * magnitud2));

    if (enGrados) {
        angulo = angulo * (180.0 / 3.14159265358979323846); //PI
    }

    return angulo;
}

int main() {
    Punto p1, p2, p3, p4;

    cout << "Ingrese las coordenadas del primer segmento (x1 y1 x2 y2): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cout << "Ingrese las coordenadas del segundo segmento (x3 y3 x4 y4): ";
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    double anguloRadianes = calcularAngulo(p1, p2, p3, p4);
    cout << "El angulo en el punto de cruce es: " << anguloRadianes << " radianes." << endl;

    double anguloGrados = calcularAngulo(p1, p2, p3, p4, true);
    cout << "El angulo en el punto de cruce es: " << anguloGrados << " grados." << endl;

    return 0;
}
