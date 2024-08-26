#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>

// int checkBrightnessLevel(char r, char g, char b);

int main() {
    int width, height, channels;
    // FILE* output;

    unsigned char *img = stbi_load("./images/MonaLisa.jpg", &width, &height, &channels, 0);
    // output = fopen("OUTPUT.txt", "w");

    if (img == NULL) {
        printf("Error: Image Failed to Load.\n");
        return 1;
    } else {
        printf("Image loaded: %dx%d with %d channels\n", width, height, channels);
    }

    /*
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int pixel_index = (y * width + x) * channels;
                unsigned char r = img[pixel_index];
                unsigned char g = img[pixel_index + 1];
                unsigned char b = img[pixel_index + 2];

                // int brightness = checkBrightnessLevel(r, g, b);
                
            }
        }
    */

    stbi_image_free(img);
    // fclose(img);
    return 0;
}

/*
    int checkBrightnessLevel(char r, char g, char b) {
    return BrightnessLevel;
}
*/
