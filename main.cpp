#include <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E; 
public:
    // Default constructor
    Electric_Field() {
        E = new double[3];
        E[0] = 0.0; 
        E[1] = 0.0; 
        E[2] = 0.0;
    }

    // Constructor with components
    Electric_Field(double x, double y, double z) {
        E = new double[3];
        E[0] = x;
        E[1] = y;
        E[2] = z;
    }

    // Destructor
    ~Electric_Field() {
        delete[] E;
    }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    // Calculate Magnitude
    double calculateMagnitude() const {
        return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    // Calculate Inner Product
    double innerProduct(const Electric_Field &other) const {
        return E[0] * other.E[0] + E[1] * other.E[1] + E[2] * other.E[2];
    }
};

class Magnetic_Field {
private:
    double *B;
public:
    // Default constructor
    Magnetic_Field() {
        B = new double[3];
        B[0] = 0.0;
        B[1] = 0.0;
        B[2] = 0.0;
    }

    // Constructor with components
    Magnetic_Field(double x, double y, double z) {
        B = new double[3];
        B[0] = x;
        B[1] = y;
        B[2] = z;
    }

    // Destructor
    ~Magnetic_Field() {
        delete[] B;
    }

    // Getters
    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    // Setters
    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }

    // Calculate Magnitude
    double calculateMagnitude() const {
        return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    // Calculate Unit Vector
    void calculateUnitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude != 0.0) {
            std::cout << "Unit Vector: (" << B[0] / magnitude << ", " << B[1] / magnitude << ", " << B[2] / magnitude << ")\n";
        } else {
            std::cout << "Unit Vector: (0, 0, 0)\n";
        }
    }
};


int main() {
    // Create electric field objects
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);

    // Set values for E_default
    E_default.setX(5.0);
    E_default.setY(2.0);
    E_default.setZ(1.0);

    // Calculate and print magnitudes
    std::cout << "Magnitude of E_default: " << E_default.calculateMagnitude() << std::endl;
    std::cout << "Magnitude of E_components: " << E_components.calculateMagnitude() << std::endl;

    // Calculate and print inner product
    std::cout << "Inner Product of E_default and E_components: " 
              << E_default.innerProduct(E_components) << std::endl;

    // Create magnetic field objects
    Magnetic_Field B_default;
    Magnetic_Field B_components(1.5, 2.5, 3.5);

    // Set values for B_default
    B_default.setX(4.0);
    B_default.setY(1.0);
    B_default.setZ(3.0);

    // Calculate and print magnitudes
    std::cout << "Magnitude of B_default: " << B_default.calculateMagnitude() << std::endl;
    std::cout << "Magnitude of B_components: " << B_components.calculateMagnitude() << std::endl;

    // Calculate and print unit vectors
    std::cout << "B_default unit vector: ";
    B_default.calculateUnitVector();
    std::cout << "B_components unit vector: ";
    B_components.calculateUnitVector();

    return 0;
}
