
#define IMPLICIT_BIT 1  // implicit bit
#define ARR_SIZE 6

typedef enum {
    SERVO_E_NONE    =  0,   // No error/warning
    SERVO_W_FAIL    = -1,   // Warning
    SERVO_E_FAIL    = -2,   // Error when writing to slave
    SERVO_E_ACCESS  = -3    // Errror bus access
} ServoCtrlError;


// struct holding the floating point format number
typedef struct {
    char  value32bit[32]; // all 32 bits of the floating point number
    int   sign;           // 1 bit, +1 or -1
    char  exponent[8];    // exponent, 8 bits
    char  mantissa[24];   // mantissa, 24 bits
} FloatPointNumber;

// convert input decimal integer data to binary string
char* FloatPointConv_decimal2binary(int n);

// convert array of data to a binary string
void FloatPointConv_convertArray(int* indata, int offset);

// get sign bit of data
void FloatPointConv_assignSign(char* bin_data);

// get exponent
void FloatPointConv_assignExponent(char* indata);

// get mantissa
void FloatPointConv_assignMantissa(char* indata);

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
