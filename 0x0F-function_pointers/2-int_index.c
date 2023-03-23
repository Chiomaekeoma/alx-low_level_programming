#include "function_pointers.h"

/**
* int_index - searches for an integer
* @array: array pointer
* @size: size of array
* @cmp: pointer to function called
* Return: returns index of element, if element is found
*/

int int_index(int *array, int size, int (*cmp)(int))
{
        int i, index;

        if (size <= 0)
                return (-1);
        if (array == NULL || cmp == NULL)
                return (-1);

        for (i = 0; i < size; i++)
        {
                index = cmp(array[i]);
                if (index == 1)
                        return (i);
        }

        return (-1);
}
