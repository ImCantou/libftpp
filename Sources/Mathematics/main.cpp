#include <cmath>
#include "../../Includes/Utils/ppm.hpp"
#include "../../Includes/Mathematics/perlin_noise_2D.hpp"

int main() {
	// Define the size of the image
	unsigned int width = 2048, height = 2048;

	// Create an empty PPM image
	ppm image(width, height);
	
	PerlinNoise pn;

	unsigned int kk = 0;
	// Visit every pixel of the image and assign a color generated with Perlin noise
	for(unsigned int i = 0; i < height; ++i) {     // y
		for(unsigned int j = 0; j < width; ++j) {  // x
			double x = (double)j/((double)width);
			double y = (double)i/((double)height);

			// Typical Perlin noise
			double n = pn.sample(10 * x, 10 * y);

			// Map the values to the [0, 255] interval, for simplicity we use 
			// tones of grey
			image.r[kk] = floor(255 * n);
			image.g[kk] = floor(255 * n);
			image.b[kk] = floor(255 * n);
			kk++;
		}
	}

	// Save the image in a binary PPM file
	image.write("perlin.ppm");

	return 0;
}