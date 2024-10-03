#include <stdio.h>

float celsius_to_fahrenheit (float celsius);
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
void categorize_temperature(float celsius);

int main() {
	float temperature;
	float convertedTemperature;
	float celciusTemperature;
	int inputUnit;
	int outputUnit;

	printf("Enter the temperature: ");
	scanf("%f", &temperature);
	printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
	scanf("%d", &inputUnit);
	printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
	scanf("%d", &outputUnit);
	printf("\n");

	if (inputUnit == 1) {
		if (outputUnit == 1) {
			convertedTemperature = temperature;
		} else if (outputUnit == 2) {
			convertedTemperature = celsius_to_fahrenheit(temperature);
		} else if (outputUnit == 3) {
			convertedTemperature = celsius_to_kelvin(temperature);
		}
		celciusTemperature = temperature;
	} else if (inputUnit == 2) {
		if (outputUnit == 1) {
			convertedTemperature = fahrenheit_to_celsius(temperature);
		} else if (outputUnit == 2) {
			convertedTemperature = temperature;
		} else if (outputUnit == 3) {
			convertedTemperature = celsius_to_kelvin(fahrenheit_to_celsius(temperature));
		}
		celciusTemperature = fahrenheit_to_celsius(temperature);
	} else if (inputUnit == 3) {
		if (outputUnit == 1) {
			convertedTemperature = kelvin_to_celsius(temperature);
		} else if (outputUnit == 2) {
			convertedTemperature = celsius_to_fahrenheit(kelvin_to_celsius(temperature));
		} else if (outputUnit == 3) {
			convertedTemperature = temperature;
		}
		celciusTemperature = kelvin_to_celsius(temperature);
	}

	printf("Converted temperature: %.2f\n", convertedTemperature);

	// Categorize
	categorize_temperature(celciusTemperature);

	return 0;
}

float celsius_to_fahrenheit (float celsius) {
	return (9/5)*celsius + 32;
}

float fahrenheit_to_celsius (float fahrenheit) {
	return (5/9)*(fahrenheit - 32);
}

float celsius_to_kelvin (float celsius) {
	return celsius + 273.15;
}

float kelvin_to_celsius (float kelvin) {
	return kelvin - 273.15;
}

void categorize_temperature(float celsius) {
	if (celsius < 0) {
		printf("Temperature category: Feezing\n");
		printf("Weather advisory: Stay indoors\n");
	} else if (celsius < 10) {
		printf("Temperature category: Cold\n");
		printf("Weather advisory: Wear a jacket\n");
	} else if (celsius < 25) {
		printf("Temperature category: Comfortable\n");
		printf("Weather advisory: You should feel comfortable.\n");
	} else if (celsius < 35) {
		printf("Temperature category: Hot\n");
		printf("Weather advisory: Wear light clothing\n");
	} else {
		printf("Temperature category: Extreme Heat\n");
		printf("Weather advisory: Stay hydrated\n");
	}
}