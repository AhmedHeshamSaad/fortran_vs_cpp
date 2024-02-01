#include <cstdio>
#include <vector>
#include <cstring>

int main() {
    std::vector<float> array1 = {1, 2, 3, 4, 5};
    std::vector<float> array2 = {6, 7, 8, 9, 10};

    // Writing to the file
    FILE* file = fopen("data_cpp.txt", "w");
    if (!file) {
        perror("Failed to open file for writing");
        return -1;
    }
    fprintf(file, "# Array1  Array2\n");
    for (size_t i = 0; i < array1.size(); ++i) {
        fprintf(file, "%f\t%f\n", array1[i], array2[i]);
    }
    fclose(file);

    // Reading from the file
    file = fopen("data_cpp.txt", "r");
    if (!file) {
        perror("Failed to open file for reading");
        return -1;
    }
    char line[256];
    float val1, val2;
    while (fgets(line, sizeof(line), file)) {

        if (line[0] == '#') continue; // Skip comments

        if (sscanf(line, "%f%f", &val1, &val2) == 2) {
            printf("%f\t%f\n", val1, val2);
        }
    }
    fclose(file);

    return 0;
}
