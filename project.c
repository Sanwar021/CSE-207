#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
} Row;

typedef struct {
    Row* rows;
    int capacity;
    int size;
} DynamicTable;

void initializeTable(DynamicTable* table, int initialCapacity) {
    table->rows = (Row*)malloc(initialCapacity * sizeof(Row));
    table->capacity = initialCapacity;
    table->size = 0;
}

void addRow(DynamicTable* table, Row row) {
    if (table->size == table->capacity) {
        // If the table is full, increase its capacity
        table->capacity *= 2;
        table->rows = (Row*)realloc(table->rows, table->capacity * sizeof(Row));
    }
    
    table->rows[table->size++] = row;
}

void removeRow(DynamicTable* table, int rowIndex) {
    if (rowIndex < 0 || rowIndex >= table->size) {
        printf("Invalid row index!\n");
        return;
    }
    
    for (int i = rowIndex; i < table->size - 1; i++) {
        table->rows[i] = table->rows[i + 1];
    }
    
    table->size--;
}

void printTable(DynamicTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("Row %d: ID=%d, Name=%s\n", i, table->rows[i].id, table->rows[i].name);
    }
}

void freeTable(DynamicTable* table) {
    free(table->rows);
    table->rows = NULL;
    table->capacity = 0;
    table->size = 0;
}

int main() {
    DynamicTable table;
    initializeTable(&table, 2);
    
    Row row1 = { 1, "John" };
    Row row2 = { 2, "Alice" };
    Row row3 = { 3, "Bob" };
    
    addRow(&table, row1);
    addRow(&table, row2);
    addRow(&table, row3);
    
    printf("Table size: %d\n", table.size);
    printTable(&table);
    
    removeRow(&table, 1);
    
    printf("Table size after removing a row: %d\n", table.size);
    printTable(&table);
    
    freeTable(&table);
    
    return 0;
}
