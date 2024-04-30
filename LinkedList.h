#include "RefrigeratorService.h"

typedef struct Node {
    Ingredient data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int count;
} List;

void InitList(List** list) {
    (*list) = (List*)malloc(sizeof(list));
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->count = 0;
}

Node* CreateNode(Ingredient data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
Node* FindNode(List** list, int index) {
    if (!(*list)) return NULL;

    int idx = 1;
    int cnt = (*list)->count;
    Node* n = (*list)->head;

    while (idx < index) {

        n = n->next;
        idx++;
    }
    return n;


}

void DelNode(List** list, Node* n) {
    if (!(*list) || !n)return;

    printf("Delete Node data : %s\n\n", n->data.name);

    if ((*list)->count == 1) {
        (*list)->head = (*list)->tail = NULL;
        free(n);
    }
    else {
        if ((*list)->head == n) {
            (*list)->head = n->next;
        }
        else if ((*list)->tail == n) {
            (*list)->tail = n->prev;
        }
        n->prev->next = n->next;
        n->next->prev = n->prev;

        free(n);
    }
    (*list)->count--;

}

void AddNode(List** list, Node* node) {
    if (!(*list) || !node) return;
    printf("\nAdd Ingredient - data : %s\n", node->data.name);

    if ((*list)->count == 0) {
        (*list)->head = (*list)->tail = node;
        node->next = node->prev = node;
    }
    else {
        node->prev = (*list)->tail;
        node->next = (*list)->head;
        (*list)->tail->next = node;
        (*list)->head->prev = node;
        (*list)->tail = node;
    }

    (*list)->count++;
}


void printAllNode(List** list) {
    if (!(*list)) return;
    printf("\n");
    if ((*list)->count == 0) {
        printf(" |                    _    |   _                    |\n");
        printf(" |                   | |   |  | |                   |\n");
        printf(" |                   |_|   |  |_|                   |\n");
        printf(" |                         |                        |\n");
        printf(" |                                                  |\n");
        printf(" |          \x1b[38;2;255;165;0m### Refrigerator is empty ###\x1b[0m           |\n");
        printf(" |                                                  |\n");
        printf(" |                         |                        |\n");
        printf(" |_________________________|________________________|\n");
        return;
    }
    
    printf(" |                                                  |\n");
    printf(" |               \x1b[38;2;255;165;0m### Print All Food ###\x1b[0m             |\n");
    printf(" |                                                  |\n");
    int idx = 1;
    int cnt = (*list)->count;
    Node* n = (*list)->head;

    while (idx <= cnt) {
        printf(" |                    _    |   _                    |\n");
        printf(" |                   | |   |  | |                   |\n");
        printf(" |                   |_|   |  |_|                   |\n");
        printf(" |                                                  |\n");
        printf(" |=======================[ %d ]======================|\n", idx);
        printf(" |                                                  |\n");
        printf(" |                         |                        |\n");
        printf(" |                         |                        |\n");
        printf(" |   Ingredient Name : %s                           \n", n->data.name);
        printf(" |   Ingredient Use By Date : %d day left           \n", n->data.UseByDate);
        printf(" |   Ingredient Volume : %d g is left               \n", n->data.Volume);
        printf(" |                                                  |\n");
        printf(" |                         |                        |\n");
        printf(" |_________________________|________________________|\n");
        n = n->next;
        idx++;
    }
    printf("\n");
}
void GetFoodInfo(Ingredient* food) {
    system("cls");
    printf("  __________________________________________________\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |      \x1b[38;2;255;165;0mFOOD FIGHTER\x1b[0m       |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                                                  |\n");
    printf(" |  Please type the food name: ");
    getchar();
    scanf("%[^\n]", food->name);
    getchar();
    printf(" |                                                  |\n");

    printf(" |  Please type the food use by date: ");
    scanf("%d", &food->UseByDate);
    getchar();
    printf(" |                                                  |\n");
    printf(" |  Please type the food volume (Unit : g) : ");
    scanf("%d", &food->Volume);
    getchar();
    printf(" |                                                  |\n");
    printf(" |                         |                        |\n");
    printf(" |                    _    |   _                    |\n");
    printf(" |                   | |   |  | |                   |\n");
    printf(" |                   |_|   |  |_|                   |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |====================== Check =====================|\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |    Food name: %s\n", food->name);
    printf(" |                                                  |\n");
    printf(" |    Food use by date: %d day left\n", food->UseByDate);
    printf(" |                                                  |\n");
    printf(" |    Food volume (Unit : g) : %d g\n", food->Volume);
    printf(" |                                                  |\n");
    printf(" |                         |                        |\n");
    printf(" |_________________________|________________________|\n");

}
void ShowRecipe() {
    int numPredefinedRecipes = sizeof(PredefinedRecipe) / sizeof(Food);

    for (int i = 0; i < numPredefinedRecipes; i++) {
        printf("====================== [\x1b[38;2;255;165;0m%d\x1b[0m] =====================\n\n", i);
        printf("  Recipe Name: %s\n\n", PredefinedRecipe[i].name);
        printf("  Recipe Difficulty: \n\n", PredefinedRecipe[i].name);
        for (int j = 0; j < PredefinedRecipe[i].Difficulty; j++) {
            printf("  %s", "\u2605");
        }
        for (int j = PredefinedRecipe[i].Difficulty; j < 5; j++) {
            printf("  %s", "\u2606");
        }
        printf("\n\n");
        printf("  Recipe Cooking Time: %d\n\n", PredefinedRecipe[i].CookTime);
        // 재료 출력
        printf("  Ingredients:\n");
        for (int j = 0; j < sizeof(PredefinedRecipe[i].Material) / sizeof(Ingredient); j++) {
            Ingredient ingredient = PredefinedRecipe[i].Material[j];
            if (strlen(ingredient.name) == 0) // 재료 이름이 빈 문자열인 경우 더 이상 재료가 없음
                break;
            printf("   - %s (Use By Date: %d, Volume: %d)\n", ingredient.name, ingredient.UseByDate, ingredient.Volume);
        }
        printf("\n");

    }
}

void RecomandRecipe(List** list) {
    int numPredefinedRecipes = sizeof(PredefinedRecipe) / sizeof(Food);
    system("cls");

    for (int i = 0; i < numPredefinedRecipes; i++) {
        int allIngredientsFound = 1; // 모든 재료가 발견되었는지를 추적하는 플래그

        for (int j = 0; j < sizeof(PredefinedRecipe[i].Material) / sizeof(Ingredient); j++) {
            Ingredient ingredient = PredefinedRecipe[i].Material[j];
            if (strlen(ingredient.name) == 0) // 더 이상 재료가 없으면 중지
                break;

            int ingredientFound = 0; // 현재 재료가 발견되었는지를 추적하는 플래그
            Node* n = (*list)->head;
            for (int k = 0; k < (*list)->count; k++) {
                if (strcmp(ingredient.name, n->data.name) == 0 &&
                    ingredient.UseByDate <= n->data.UseByDate &&
                    ingredient.Volume <= n->data.Volume) {
                    ingredientFound = 1;
                    break;
                }
                n = n->next;
            }

            // 재료가 발견되지 않았거나 수량이 충분하지 않으면 플래그를 false로 설정하고 중단
            if (!ingredientFound) {
                allIngredientsFound = 0;
                break;
            }
        }

        // 모든 재료가 발견되고 충분한 경우에만 레시피를 출력합니다.
        if (allIngredientsFound) {
            printf("====================== [\x1b[38;2;255;165;0m%d\x1b[0m] =====================\n\n", i);
            printf("  Recipe Name: %s\n\n", PredefinedRecipe[i].name);
            printf("  Recipe Difficulty: ");
            for (int j = 0; j < PredefinedRecipe[i].Difficulty; j++) {
                printf("%s", "\u2605");
            }
            for (int j = PredefinedRecipe[i].Difficulty; j < 5; j++) {
                printf("%s", "\u2606");
            }
            printf("\n\n");
            printf("  Recipe Cooking Time: %d\n\n", PredefinedRecipe[i].CookTime);
            // 재료
            printf("  Ingredients:\n");
            for (int j = 0; j < sizeof(PredefinedRecipe[i].Material) / sizeof(Ingredient); j++) {
                Ingredient ingredient = PredefinedRecipe[i].Material[j];
                if (strlen(ingredient.name) == 0) // 더 이상 재료가 없으면 중지
                    break;
                printf("  - %s (Use By Date: %d, Volume: %d g)\n", ingredient.name, ingredient.UseByDate, ingredient.Volume);
            }
            printf("\n");
        }
    }
}


void ShowMenuBar() {
    system("cls");
    printf("  __________________________________________________\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                                                  |\n");
    printf(" |      ============ \x1b[38;2;255;165;0mFOOD FIGHTER\x1b[0m ===========       |\n");
    printf(" |      [1] Food Input                              |\n");
    printf(" |                         |                        |\n");
    printf(" |      [2] Food Check                              |\n");
    printf(" |                         |                        |\n");
    printf(" |      [3] Throw away the ingredient               |\n");
    printf(" |                         |                        |\n");
    printf(" |      [4] Possible Recipe                         |\n");
    printf(" |                         |                        |\n");
    printf(" |      [0 or else] Process Close                   |\n");
    printf(" |      =====================================       |\n");
    printf(" |                         |                        |\n");
    printf(" |                    _    |   _                    |\n");
    printf(" |                   | |   |  | |                   |\n");
    printf(" |                   |_|   |  |_|                   |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |                         |                        |\n");
    printf(" |_________________________|________________________|\n");
}

void GUI(List** list) {
    int SystemFlag = 1;
    while (SystemFlag) {
        int TodoIndex;
        ShowMenuBar();
        scanf("%d", &TodoIndex);
        int ControlFlag = 1;
        switch (TodoIndex) {
        case 1:
            system("cls");
            printf("==============================\n\n");
            printf("Food Input\n\n");
            printf("==============================\n\n");

            while (1) {
                Ingredient food;
                GetFoodInfo(&food);
                AddNode(list, CreateNode(food));
                printf("If you want to input more ingredient, enter 1: \n");
                printf("or if you want to stop about inputing ingredient, enter 0: ");
                scanf("%d", &ControlFlag);
                if (ControlFlag == 0) break;
                else system("cls");
            }
            break;

        case 2:
            system("cls");
            printf("  __________________________________________________\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |    \x1b[38;2;255;165;0mIngredient Check\x1b[0m     |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |");
            printAllNode(list);

            printf("If you want to stop about checking ingredient, enter 0: ");
            scanf("%d", &ControlFlag);
            break;

        case 3:
            system("cls");
            printf("  __________________________________________________\n");
            printf(" |                         |                        |\n");
            printf(" |                                                  |\n");
            printf(" |  \x1b[38;2;255;165;0mThrow away the ingredient\x1b[0m                       |\n");
            printf(" |                                                  |\n");
            printf(" |                         |                        |");

            while (1) {
                printAllNode(list);
                printf("If you want to throw away the ingredient, enter index: ");
                scanf("%d", &ControlFlag);
                DelNode(list, FindNode(list, ControlFlag));

                printf("If you want to throw more ingredient, enter 3. \n");
                printf("or if you want to return to the main menu, enter 0: ");
                scanf("%d", &ControlFlag);
                if (ControlFlag == 0) {
                    break; // 메인 화면으로 돌아가는 부분
                }
            }
            break;


        case 4:
            system("cls");
            printf(" ===============================================\n");
            printf("|                                               |\n");
            printf("|            \x1b[38;2;255;165;0mCheck Possible Recipe\x1b[0m              |\n");
            printf("|                                               |\n");
            printf(" ===============================================\n\n");
            ShowRecipe();
            printf("If you want to see about recomend recipe, enter 0: ");
            scanf("%d", &ControlFlag);
            if (ControlFlag == 0) RecomandRecipe(list);
            printf("If you want to stop about checking ingredient, enter 0: ");

            scanf("%d", &ControlFlag);
            break;

        default:
            system("cls");
            printf("  __________________________________________________\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                                                  |\n");
            printf(" |            \x1b[38;2;255;165;0mRefrigerator Service Close\x1b[0m            |\n");
            printf(" |                                                  |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                    _    |   _                    |\n");
            printf(" |                   | |   |  | |                   |\n");
            printf(" |                   |_|   |  |_|                   |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |                         |                        |\n");
            printf(" |_________________________|________________________|\n");
            SystemFlag = 0;
            break;
        }

    }
}
