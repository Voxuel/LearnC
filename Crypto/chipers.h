

struct chiperinput {
    char *key;
    char *plaintext;
    int len;
};

struct chiperResult {
	char *data;
	int len;
};


typedef struct chiperinput CipherInput;
typedef struct chiperResult ChiperResult;

ChiperResult run_xor(CipherInput *chiper_input);