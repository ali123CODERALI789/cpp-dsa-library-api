#pragma once
template<typename Temp>
Temp BinarySearch(Temp arr[], int first, int last, Temp index)
{
    if (first > last)
        return Temp();

    int middle = (first + last) / 2;

    if (arr[middle] == index)

        return middle;
    else if (arr[middle] < index)

        return BinarySearch<Temp>(arr, middle + 1, last, index);
    else
        return BinarySearch<Temp>(arr, first, middle - 1, index);
}
template<typename Temp>
Temp LinearSearch(Temp arr[], int numElems, Temp value)
{
    int index = 0, position = -1;
    bool found = false;
    while (!found && index < numElems)
    {
        if (arr[index] == value)
        {
            found = true;
            position = index;
            return position;
        }
        index++;
    }
    return Temp();
}