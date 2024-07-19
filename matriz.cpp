#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 10;

bool inversaMatriz(float mat[MAX][MAX], float inv[MAX][MAX], int n) {
    float temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = mat[i][j];
            inv[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
    for (int i = 0; i < n; i++) {
        float diagElement = temp[i][i];
        if (diagElement == 0) {
            return false;
        }

        for (int j = 0; j < n; j++) {
            temp[i][j] /= diagElement;
            inv[i][j] /= diagElement;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                float coeff = temp[k][i];
                for (int j = 0; j < n; j++) {
                    temp[k][j] -= coeff * temp[i][j];
                    inv[k][j] -= coeff * inv[i][j];
                }
            }
        }
    }

    return true;
}

void multiplicarMatrices(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int filaA, int colA, int colB) {
    for (int i = 0; i < filaA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int main() {
    int fila1, columna1, fila2, columna2, opc;
    
    cout << "Ingresa el numero de filas de la primera matriz: "; 
    cin >> fila1;
    cout << "Ingresa el numero de columnas de la primera matriz: "; 
    cin >> columna1;
    cout << "Ingresa el numero de filas de la segunda matriz: "; 
    cin >> fila2;
    cout << "Ingresa el numero de columnas de la segunda matriz: "; 
    cin >> columna2;
    
    float matriz1[MAX][MAX], matriz2[MAX][MAX];
    
    cout << "Matriz 1: \n";
    for (int x = 0; x < fila1; x++) {
        for (int y = 0; y < columna1; y++) {
            cout << "Ingresa el elemento: [" << x + 1 << "][" << y + 1 << "]: ";
            cin >> matriz1[x][y];
        }
    }
    
    cout << "Matriz 2: \n";
    for (int i = 0; i < fila2; i++) {
        for (int j = 0; j < columna2; j++) {
            cout << "Ingresa el elemento: [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }
    
    do {
        cout << "Menu \n\n";
        cout << "1) Suma\n";
        cout << "2) Resta\n";
        cout << "3) Multiplicacion\n";
        cout << "4) Division\n";
        cout << "Elige una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                if (columna1 == columna2 && fila1 == fila2) {
                    float matriz3[MAX][MAX];
                    for (int a = 0; a < fila1; a++) {
                        for (int b = 0; b < columna2; b++) {
                            matriz3[a][b] = matriz1[a][b] + matriz2[a][b];
                        }
                    }
                    cout << "El resultado es:\n\n";
                    for (int x = 0; x < fila1; x++) {
                        for (int y = 0; y < columna2; y++) {
                            cout << "  " << matriz3[x][y] << "  ";
                        }
                        cout << "\n";
                    }
                } else {
                    cout << "Las matrices no cumplen con el tamaño necesario para dicha operacion\n";
                }
                break;
            case 2:
                if (columna1 == columna2 && fila1 == fila2) {
                    float matriz3[MAX][MAX];
                    for (int a = 0; a < fila1; a++) {
                        for (int b = 0; b < columna2; b++) {
                            matriz3[a][b] = matriz1[a][b] - matriz2[a][b];
                        }
                    }
                    cout << "El resultado es:\n\n";
                    for (int x = 0; x < fila1; x++) {
                        for (int y = 0; y < columna2; y++) {
                            cout << "  " << matriz3[x][y] << "  ";
                        }
                        cout << "\n";
                    }
                } else {
                    cout << "Las matrices no cumplen con el tamaño necesario para dicha operacion\n";
                }
                break;
            case 3:
                if (columna1 == fila2) {
                    float matriz3[MAX][MAX];
                    multiplicarMatrices(matriz1, matriz2, matriz3, fila1, columna1, columna2);
                    cout << "El resultado es:\n\n";
                    for (int x = 0; x < fila1; x++) {
                        for (int y = 0; y < columna2; y++) {
                            cout << "  " << matriz3[x][y] << "  ";
                        }
                        cout << "\n";
                    }
                } else {
                    cout << "Las matrices no cumplen con el tamaño necesario para dicha operacion\n";
                }
                break;
            case 4:
                if (columna1 == fila2) {
                    if (fila2 != columna2) {
                        cout << "La segunda matriz debe ser cuadrada para tener una inversa.\n";
                        break;
                    }

                    float inversa[MAX][MAX];
                    if (!inversaMatriz(matriz2, inversa, fila2)) {
                        cout << "La segunda matriz no es invertible.\n";
                        break;
                    }
                    float resultado[MAX][MAX];
                    multiplicarMatrices(matriz1, inversa, resultado, fila1, columna1, columna2);

                    cout << "Resultado de la multiplicación de la primera matriz por la inversa de la segunda matriz:\n";
                    for (int i = 0; i < fila1; i++) {
                        for (int j = 0; j < columna2; j++) {
                            cout << fixed << setprecision(2) << resultado[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Las matrices no cumplen con el tamaño necesario para dicha operacion\n";
                }
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }

        cout << "¿Realizar otra operacion? si = 1 / no = 0: ";
        cin >> opc;
    } while (opc == 1);

    return 0;
}
