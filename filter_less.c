#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // calculate average for RGB values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double red = image[i][j].rgbtRed;  // integer division truncates values, so rgb vals must be stored in d or f
            double green = image[i][j].rgbtGreen;
            double blue = image[i][j].rgbtBlue;
            int avg = round((red + blue + green) / 3);

            // set RGB byte values for the RGB triple struct
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*
      sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
      sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
      sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // calculate sepia values
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // cap max values at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // set RGB byte values for the RGB triple struct
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    for each row, switch pixels on horizontally opposite sides with center pix as reference
    */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)  // if width is not divided by 2, another horiz flip will occur = orig image
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of original image so that the numbers do not get changed in place
    RGBTRIPLE new_img[height][width];
    // iterate over each pixel of original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set up a bounding box to blur
            int top = 0;
            int bottom = 0;
            int left = 0;
            int right = 0;
            // set top bound of box
            if (i - 1 >= 0)
            {
                top = i - 1;
            }
            else
            {
                top = i;
            }
            // set bottom bound of box
            if (i + 1 < height)
            {
                bottom = i + 1;
            }
            else
            {
                bottom = i;
            }
            // set left bound of box
            if (j - 1 >= 0)
            {
                left = j - 1;
            }
            else
            {
                left = j;
            }
            // set right bound of box
            if (j + 1 < width)
            {
                right = j + 1;
            }
            else
            {
                right = j;
            }

            // loop through 2d box array made with top-bottom-left-right bounds
            double red = 0;
            double green = 0;
            double blue = 0;
            for (int m = top; m <= bottom; m++)
            {
                for (int n = left; n <= right; n++)
                {
                    red += image[m][n].rgbtRed;
                    green += image[m][n].rgbtGreen;
                    blue += image[m][n].rgbtBlue;
                }
            }

            // calculate avg r, g, b values of all pixels within box
            int avg_red = round(red / ((bottom - top + 1) * (right - left + 1)));
            int avg_green = round(green / ((bottom - top + 1) * (right - left + 1)));
            int avg_blue = round(blue / ((bottom - top + 1) * (right - left + 1)));

            // set pixel of new image creatd with the blurred rgb values
            new_img[i][j].rgbtRed = avg_red;
            new_img[i][j].rgbtGreen = avg_green;
            new_img[i][j].rgbtBlue = avg_blue;

        }
    }

    // replace each pixel of original image with that of new image after all calcs are finished
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_img[i][j];
        }
    }

    return;
}
