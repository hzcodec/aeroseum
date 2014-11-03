#define IMPLICIT_BIT 1  // implicit bit
#define ARR_SIZE 6


// struct holding the floating point format number
typedef struct {
    char  value32bit[32]; // all 32 bits of the floating point number
    int   sign;           // 1 bit, +1 or -1
    char  exponent[8];    // exponent, 8 bits
    char  mantissa[24];   // mantissa, 24 bits
} FloatPointNumber;


// convert input decimal integer data to binary string
char* decimal2binary(int n);

// convert array of data to a binary string
void convert_array(int* indata, int offset);

// get sign bit of data
void assign_sign(char* bin_data);

// get exponent
void assign_exponent(char* indata);

// get mantissa
void assign_mantissa(char* indata);

// convert the exponent to decimal number
int FloatPointConv_bin2dec(char* indata);

// convert the mantissa to decimal number
int FloatPointConv_bin2dec2(char* indata);

// calculate 1/2^n
float FloatPointConv_powerOf2n(int x);

// calculate 2^n
float FloatPointConv_powerOf2(int n);

// calculate floating point value
float FloatPointConv_calcFloatingPointValue(FloatPointNumber fpNo, int dec_exponent);

// get float value from in data
float FloatPointConv_getFloatData(int* data, int offset);
