#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int width, height, channels;
    FILE* output;

    unsigned char *img = stbi_load("./images/lena.jpg", &width, &height, &channels, 0);
    output = fopen("OUTPUT.txt", "w");

    if (img == NULL) {
        printf("Error: Image Failed to Load.\n");
        return 1;
    } else {
        printf("Image loaded: %dx%d with %d channels\n", width, height, channels);
    }


    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * channels;
            unsigned char r = img[pixel_index];
            unsigned char g = img[pixel_index + 1];
            unsigned char b = img[pixel_index + 2];

            float brightness = ((r + g + b) / 3.0) / 255.0;

            if (brightness < .20)  {
                fprintf(output, " ");
            } else if (brightness >= .20 && brightness < .30) {
                fprintf(output, ".");
            } else if (brightness >= .30 && brightness < .40) {
                fprintf(output, ":");
            } else if (brightness >= .40 && brightness < .50) {
                fprintf(output, "-");
            } else if (brightness >= .50 && brightness < .60) {
                fprintf(output, "=");
            } else if (brightness >= .60 && brightness < .80) {
                fprintf(output, "#");
            } else if (brightness >= .80) {
                fprintf(output, "@");
            }
            
        }
        fprintf(output, "\n");
    }

    printf("File Converted\n");

    stbi_image_free(img);
    fclose(output);
    return 0;
}