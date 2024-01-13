#include <stdio.h>
int draw_rectangle(int width, int length, char character);
int draw_triangle(int size, char character);
int valid_character(char character);

int main() {
    int request;
    int width, length, size;
    char rect_char, triangle_char;

    int quit = 0; 

    while (!quit) {
        printf("Enter 1(rectangle), 2(triangle), 3(other), 0(quit): ");
        scanf(" %d", &request);

        if (request == 0) {
            printf("Bye Bye.\n");
            quit = 1; 

        } else if (request == 1) {
            printf("Enter character, width and length: ");
            scanf(" %c %d %d", &rect_char, &length, &width);
	    if (width <= 0 || length <= 0) {
                printf("Invalid data provided.\n");
            } else {
                draw_rectangle(width, length, rect_char);
            }  
            
        } else if (request == 2) {
            printf("Enter character and size: ");
            scanf(" %c  %d", &triangle_char, &size);
	     if (size <= 0) {
                printf("Invalid data provided.\n");
            } else {
                draw_triangle(size, triangle_char);
            }
  
	} else if(!valid_character(request)) { 
	  printf("Invalid choice.\n");
	} 
    }

    return 0;
}


int draw_rectangle(int width, int length, char character) {
   int i;
   int j;
   if (!valid_character(character)) {
      printf("Invalid data provided.\n");
        return 0;
    }

    for (i = 0; i < length; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", character);
        }
        printf("\n");
    }
    
    return 1;
}

int draw_triangle(int size, char character) {
   int i;
   int j;
   if (!valid_character(character)) {
      printf("Invalid data provided.\n");
        return 0;
    }

  for (i = 0; i < size; i++) {
        for (j = 0; j < (size - i - 1); j++) {
            printf(" "); 
        }
        for (j = 0; j < (2 * i + 1); j++) {
            printf("%c", character); 
        }
        printf("\n");
    }
    
    return 1;
}

int valid_character(char character) {
    return (character == '*' || character == '%' || character == '#');
}





