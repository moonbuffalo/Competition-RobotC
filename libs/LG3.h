
#ifndef LG3_H
#define LG3_H

#define L3G_DEVICE_AUTO 0
#define L3G4200D_DEVICE 1
#define L3GD20_DEVICE   2

// SA0 states

#define L3G_SA0_LOW  0
#define L3G_SA0_HIGH 1
#define L3G_SA0_AUTO 2

// register addresses

#define L3G_WHO_AM_I      0x0F

#define L3G_CTRL_REG1     0x20
#define L3G_CTRL_REG2     0x21
#define L3G_CTRL_REG3     0x22
#define L3G_CTRL_REG4     0x23
#define L3G_CTRL_REG5     0x24
#define L3G_REFERENCE     0x25
#define L3G_OUT_TEMP      0x26
#define L3G_STATUS_REG    0x27

#define L3G_OUT_X_L       0x28
#define L3G_OUT_X_H       0x29
#define L3G_OUT_Y_L       0x2A
#define L3G_OUT_Y_H       0x2B
#define L3G_OUT_Z_L       0x2C
#define L3G_OUT_Z_H       0x2D

#define L3G_FIFO_CTRL_REG 0x2E
#define L3G_FIFO_SRC_REG  0x2F

#define L3G_INT1_CFG      0x30
#define L3G_INT1_SRC      0x31
#define L3G_INT1_THS_XH   0x32
#define L3G_INT1_THS_XL   0x33
#define L3G_INT1_THS_YH   0x34
#define L3G_INT1_THS_YL   0x35
#define L3G_INT1_THS_ZH   0x36
#define L3G_INT1_THS_ZL   0x37
#define L3G_INT1_DURATION 0x38
#define L3G_LOW_ODR       0x39

typedef struct {
	float x,y,z;
} vector;

typedef struct {
	ubyte _device;
	ubyte address;
	I2CSensor port;
	vector g;
} LG3;

bool LG3_init(LG3* sensor, byte device, byte sa0);

void enableDefault(const LG3* this);

void writeReg(const LG3* this, byte reg, byte value);
byte readReg(const LG3* this, byte reg);

void read(LG3* this);

static void vector_cross(const vector* a, const vector* b, vector* out);
static float vector_dot(const vector* a, const vector* b);
static void vector_normalize(vector* a);

bool autoDetectAddress(LG3* this);

#endif