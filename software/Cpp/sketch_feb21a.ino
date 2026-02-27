#include <Arduino.h>

//Pi calc function
double gregory_leibnitz(unsigned long long leib_num) {
    double calc = 0.0;
    bool pos = true;
    unsigned long long div_num = 1;

    for (unsigned long long i = 0; i < leib_num; i++) {
        if (pos) {
            calc += 1.0 / div_num;
        } else {
            calc -= 1.0 / div_num;
        }

        pos = !pos;
        div_num += 2;      // Next odd number
    }

    return 4.0 * calc;
}

void setup() {
    Serial.begin(115200);
    delay(2000);

    unsigned long long iterations = 1000000; 
    
    Serial.println("Calculating Pi...");
    int64_t start = esp_timer_get_time();   // microseconds
    double result = gregory_leibnitz(iterations);
    int64_t end = esp_timer_get_time();

    Serial.print("Iterations: ");
    Serial.println(iterations);

    Serial.print("Approximated Pi: ");
    Serial.println(result, 10);

    Serial.print("Calculation Time (µs): ");
    Serial.println(end - start);

    Serial.print("Calculation Time (ms): ");
    Serial.println((end - start) / 1000.0);

    Serial.print("Calculation Time (seconds): ");
    Serial.println((end - start) / 1000000.0);
}

void loop() {
    // Nothing here
}
