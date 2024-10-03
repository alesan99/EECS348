#include <stdio.h>

float celsius_to_fahrenheit (float celsius);
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
float fahrenheit_to_kelvin (float fahrenheit);
float kelvin_to_fahrenheit (float kelvin);
void categorize_temperature(float celsius);

int main() {
	float temperature; // input temperature
	float convertedTemperature; // output temperature
	float celciusTemperature; // celcius temperature specifically, needed for categorization
	int inputScale; // 1 = Celsius, 2 = Fahrenheit, 3 = Kelvin
	int outputScale; // same as above

	// Prompt user for input
	while (1) {
		printf("Enter the temperature: ");
		scanf("%f", &temperature);
		printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
		scanf("%d", &inputScale);
		printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
		scanf("%d", &outputScale);
		printf("\n");

		// Validate inputs
		// no negative kelvin
		if (inputScale == 3 && temperature < 0) {
			printf("Invalid temperature for Kelvin. Must be a positive value.\n");
			continue; // try again
		}
		// must be a valid scale
		if (inputScale < 1 || inputScale > 3) {
			printf("Invalid current scale\n");
			continue; // try again
		}
		if (outputScale < 1 || outputScale > 3) {
			printf("Invalid target scale\n");
			continue; // try again
		}
		// must be a valid conversion
		if (inputScale == outputScale) {
			printf("No conversion needed\n");
			continue; // try again
		}

		break;
	}

	// Handle all conversion cases
	convertedTemperature = temperature; // assume no conversion is neccessary by default
	if (inputScale == 1) {
		// Convert from celcius
		if (outputScale == 2) {
			convertedTemperature = celsius_to_fahrenheit(temperature);
		} else if (outputScale == 3) {
			convertedTemperature = celsius_to_kelvin(temperature);
		}
		celciusTemperature = temperature;
	} else if (inputScale == 2) {
		// Convert from fahrenheit
		if (outputScale == 1) {
			convertedTemperature = fahrenheit_to_celsius(temperature);
		} else if (outputScale == 3) {
			convertedTemperature = fahrenheit_to_kelvin(temperature);
		}
		celciusTemperature = fahrenheit_to_celsius(temperature);
	} else if (inputScale == 3) {
		// Convert from kelvin
		if (outputScale == 1) {
			convertedTemperature = kelvin_to_celsius(temperature);
		} else if (outputScale == 2) {
			convertedTemperature = kelvin_to_fahrenheit(temperature);
		}
		celciusTemperature = kelvin_to_celsius(temperature);
	}

	// Print the converted temperature
	if (outputScale == 1) {
		printf("Converted temperature: %.2f°C\n", convertedTemperature);
	} else if (outputScale == 2) {
		printf("Converted temperature: %.2f°F\n", convertedTemperature);
	} else if (outputScale == 3) {
		printf("Converted temperature: %.2f K\n", convertedTemperature);
	}

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

float fahrenheit_to_kelvin (float fahrenheit) {
	return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit (float kelvin) {
	return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
	// Describe temperature and provide an advisory
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
		printf("Weather advisory: Dress lightly\n");
	} else {
		printf("Temperature category: Extreme Heat\n");
		printf("Weather advisory: Excercise caution, stay hydrated\n");
	}
}