bool splitArrayHelper(int *input, int sumA, int sumB, int id, int n){
    if(id == n){
        if(sumA == sumB) return true;
        else return false;
    }

    if(input[id]%5 == 0){
        return splitArrayHelper(input, sumA+input[id], sumB, id+1, n);
    }

    if(input[id]%3 == 0){
        return splitArrayHelper(input, sumA, sumB+input[id], id+1, n);
    }

    if(splitArrayHelper(input, sumA+input[id], sumB, id+1, n)) return true;
    else if(splitArrayHelper(input, sumA, sumB+input[id], id+1, n)) return true;
    else return false;
}

bool splitArray(int *input, int size) {
    return splitArrayHelper(input, 0, 0, 0, size);
}
