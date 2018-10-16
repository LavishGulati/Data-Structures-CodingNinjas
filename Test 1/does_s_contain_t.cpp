bool checksequenece(char large[] , char*small) {
    int i = 0;
    for(int j = 0; large[j] != '\0'; j++){
        if(large[j] == small[i]) i++;
    }

    return small[i] == '\0';
}
