#include <iostream>
#include <vector>
#include <locale> 

using namespace std;


double averageSmoothing(const vector<double>& data, int period) {
    double sum = 0.0;
    int n = data.size();
    for (int i = n - period; i < n; i++) { 
        sum += data[i];
    }
    return sum / period;
}

double exponentialSmoothing(const vector<double>& data, double alpha) {
    double forecast = data[0];

    for (size_t i = 1; i < data.size(); i++) {
        forecast = alpha * data[i] + (1 - alpha) * forecast;
    }

    return forecast;
}

int main() {
    setlocale(LC_ALL, "rus"); 
    vector<double> data = {327, 332, 336, 326, 325, 311, 298, 276, 255, 242, 230,
                           219, 202, 184, 170, 161, 161, 170, 170, 168, 167, 164, 172, 165, 156}; 

    int method;
    
    while (true) {
        cout << "Оберiть метод прогнозування:\n";
        cout << "1. Згладжування усередненням\n";
        cout << "2. Експоненцiйне згладжування\n";
        cout << "3. Вихiд\n";
        cin >> method;
        switch (method) {
        case 1: {
            int period;
            cout << "Введiть перiод для згладжування усередненням: ";
            cin >> period;
            double forecast = averageSmoothing(data, period);
            cout << "Прогноз методом згладжування усередненням: " << forecast << endl;
            break;
        }
        case 2: {
            double alpha;
            cout << "Введiть параметр alpha для експоненцiйного згладжування (0 < alpha < 1): ";
            cin >> alpha;
            double forecast = exponentialSmoothing(data, alpha);
            cout << "Прогноз методом експоненцiйного згладжування: " << forecast << endl;
            break;
        }
        case 3: {
            exit(0);
        }
        default:
            cout << "Невірно обраний метод!" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
