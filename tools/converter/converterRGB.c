/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converterRGB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:02:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/05 15:43:41 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <png.h>

void extract_decimal_values(const char* image_path, const char* output_path) {
    FILE *fp = fopen(image_path, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file %s\n", image_path);
        return;
    }

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        fclose(fp);
        fprintf(stderr, "Error: Could not initialize PNG read structure\n");
        return;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_read_struct(&png, NULL, NULL);
        fclose(fp);
        fprintf(stderr, "Error: Could not initialize PNG info structure\n");
        return;
    }

    if (setjmp(png_jmpbuf(png))) {
        // If we get here, there was an error reading the PNG file
        fclose(fp);
        png_destroy_read_struct(&png, &info, NULL);
        fprintf(stderr, "Error: Error reading PNG file\n");
        return;
    }

    png_byte header[8];
    fread(header, 1, 8, fp);
    if (png_sig_cmp(header, 0, 8)) {
        fclose(fp);
        png_destroy_read_struct(&png, &info, NULL);
        fprintf(stderr, "Error: File is not recognized as a PNG file\n");
        return;
    }

    png_init_io(png, fp);
    png_set_sig_bytes(png, 8);

    // Read PNG info and get ready to read the image
    png_read_info(png, info);

    // Allocate memory for the row pointers
    png_bytep* row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * png_get_image_height(png, info));
    for (int y = 0; y < png_get_image_height(png, info); y++) {
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png, info));
    }

    // Read the image
    png_read_image(png, row_pointers);

    // Open the output file
    FILE *output_file = fopen(output_path, "w");
    if (!output_file) {
        fclose(fp);
        png_destroy_read_struct(&png, &info, NULL);
        fprintf(stderr, "Error: Could not open file %s for writing\n", output_path);
        return;
    }

    // Write decimal values to the output file, replace empty pixels with -1
    for (int y = 0; y < png_get_image_height(png, info); y++) {
        for (int x = 0; x < png_get_image_width(png, info); x++) {
            png_bytep px = &(row_pointers[y][x * png_get_channels(png, info)]);
            
            // Check if the pixel is empty (alpha channel is 0)
            if (png_get_channels(png, info) == 4 && px[3] == 0) {
                fprintf(output_file, "-1 ");
            } else {
                // Calculate decimal value for non-empty pixel
                uint32_t decimal_value = px[0] * 256 * 256 + px[1] * 256 + px[2];
                fprintf(output_file, "%u ", decimal_value);
            }
        }
        fprintf(output_file, "\n");
    }

    // Close the output file
    fclose(output_file);

    // Free allocated memory
    for (int y = 0; y < png_get_image_height(png, info); y++) {
        free(row_pointers[y]);
    }
    free(row_pointers);

    // Clean up libpng structures
    png_destroy_read_struct(&png, &info, NULL);

    // Close the input file
    fclose(fp);
}

int main() {
    const char* image_path = "../../texture/visual texture/shield.png";
    const char* output_path = "../../texture/code texture/shield.txt";
    extract_decimal_values(image_path, output_path);

    return 0;
}
