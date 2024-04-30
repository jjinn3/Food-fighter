#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct Ingredient {
    char name[30]; //음식 이름 
    int UseByDate; //유통 기한
    int Volume;
} Ingredient;

  
typedef struct Food {

    char name[30];
    int CookTime;
    int Difficulty;
    Ingredient Material[100];

}Food;

Food PredefinedRecipe[] = {
   {"Scramble Egg", 10, 1,
      {
         {"egg", 5, 100},
         {"oil", 5, 20}
      }
   },
   {"Pan Cake", 15, 3,
      {
         {"egg", 5, 100},
         {"milk", 5, 150},
         {"flour", 1, 200}
      }
   },
   {"Gimchi Fried Rice", 20, 3,
      {
         {"rice", 10, 400},
         {"gimchi", 8, 200},
         {"oil", 5, 20},
         {"onion", 5, 200},
         {"bacon", 5, 100}
      }
   },
   {"Egg Fried Rice", 20, 3,
      {
         {"rice", 10, 400},
         {"egg", 5, 200},
         {"oil", 5, 20},
         {"onion", 5, 200},
         {"bacon", 5, 100}
      }
   },
   {"Tomato pasta", 25, 3,
      {
         {"noodle", 10, 400},
         {"tomato souce", 5, 200},
         {"oil", 5, 20},
         {"onion", 5, 200},
         {"bacon", 5, 100},
         {"cheese", 5, 30}
      }
   },
   {"Toast", 15, 2,
      {
         {"bread", 5, 100},
         {"butter", 10, 10},
         {"jam", 5, 10}
      }
   },

    {"Beef Tacos", 20, 3,
      {
         {"beef", 10, 300},
         {"taco shells", 5, 150},
         {"lettuce", 3, 50},
         {"tomato", 2, 30},
         {"cheese", 5, 100}
      }
    },
   {"Mushroom Risotto", 30, 4,
      {
         {"rice", 10, 200},
         {"mushrooms", 8, 150},
         {"white wine", 5, 100},
         {"chicken", 5, 100},
         {"cheese", 5, 50}
      }
    },
   {"Fish and Chips", 30, 2,
      {
         {"fish", 15, 300},
         {"potatoes", 15, 200},
         {"flour", 5, 50},
         {"oil", 5, 50}
      }
   },
    {"Bibimbap", 25, 5,
      {
         {"rice", 10, 400},
         {"beef", 10, 200},
         {"carrots", 5, 100},
         {"spinach", 5, 100},
         {"bean", 5, 100},
         {"egg", 5, 50},
         {"gochujang", 5, 50}
      }
   },
    {"Kimchi Jjigae", 30, 4,
      {
         {"kimchi", 10, 300},
         {"pork belly", 10, 200},
         {"tofu", 5, 150},
         {"onion", 5, 50},
         {"gochugaru", 5, 20}
      }
   },
    {"Doenjang Jjigae", 25, 4,
      {
         {"doenjang", 10, 100},
         {"tofu", 10, 200},
         {"zucchini", 5, 100},
         {"potato", 5, 100},
         {"clams", 5, 50},
         {"onion", 5, 50}
      }
   },
   { "Dak Galbi", 30, 4,
      {
         {"chicken", 15, 300},
         {"cabbage", 10, 150},
         {"sweet potato", 5, 100},
         {"rice cake", 5, 100},
         {"gochujang", 5, 50},
         {"soy sauce", 5, 20}
      }
   },
   { "Bulgogi", 25, 3,
      {
         {"beef", 15, 300},
         {"soy sauce", 5, 50},
         {"pear", 5, 50},
         {"onion", 5, 50},
         {"oil", 5, 20}
      }
   },
   { "Gimbap", 30, 5,
      {
         {"rice", 10, 400},
         {"seaweed", 10, 200},
         {"egg", 5, 100},
         {"carrot", 5, 50},
         {"spinach", 5, 50},
         {"cucumber", 5, 50},
         {"bacon", 5, 50}
      }
   },
   { "Spaghetti Aglio e Olio", 20, 3,
      {
         {"noodle", 10, 200},
         {"garlic", 5, 50},
         {"oil", 5, 50},
         {"red pepper flakes", 5, 10}
      }
   },
   { "Peanut Butter Banana Toast", 10, 2,
      {
         {"bread", 5, 100},
         {"peanut butter", 5, 50},
         {"banana", 5, 50}
      }
   },
   { "Fruit Smoothie", 10, 2,
      {
         {"banana", 5, 100},
         {"strawberries", 5, 100},
         {"milk", 5, 150},
         {"honey", 5, 20}
      }
   },
   { "Greek Yogurt with Honey,Nuts", 5, 1,
  {
     {"greek yogurt", 5, 150},
     {"honey", 5, 20},
     {"nuts", 5, 50}
      }
   },
   { "Omelette", 10, 3,
      {
         {"eggs", 5, 100},
         {"milk", 5, 50},
         {"cheese", 5, 50},
         {"bacon", 5, 50}
      }
   },
   { "Fruit Smoothie", 5, 2,
      {
         {"fruits", 10, 200},
         {"banana", 5, 100},
         {"strawberries", 5, 100},
         {"blueberrites", 5, 100},
         {"yogurt", 5, 100}
      }
   },





};
