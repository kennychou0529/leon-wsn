#ifndef _OV7660_H
#define _OV7660_H

#include "gpio.h"
#include "sccb.h"
#include "led.h"

#define CHANGE_REG_NUM 320

#define OV7660_PCLK		1<<1 	//PORTB[1]==>IO_B[9]
#define OV7660_VSYNC		1<<6	//PORTB[6]==>IO_B[14]
#define OV7660_HREF		1<<7	//PORTB[7]==>IO_B[15]
#define OV7660_XCLK_EN	1<<0	//PORTE[0]:xclk��ʹ�ܣ��ͽ���
///////////////////////////////////////////////////////////////////////

// OV7660����ָ��
#define OV7660_WR            0x42
#define OV7660_RD            0x43

// ֡  ͬ���ź�
#define SYNC_PIN_RD()        gpio_read(PORTB,OV7660_VSYNC)
// ��  ͬ���ź�
#define HREF_PIN_RD()        gpio_read(PORTB,OV7660_HREF)
// ����ʱ���ź�
#define PCLK_PIN_RD()        gpio_read(PORTB,OV7660_PCLK)

// XCLKʱ��ʹ��,PORTE[0]==>IO_A[0]
#define XCLK_EN()            gpio_set(PORTE,0)
#define XCLK_DIS()           gpio_clr(PORTE,0)

#define 	OV7670_ROW_SIZE		320//����
#define 	OV7670_COL_SIZE		240//����

/* �������ƣ�write_OV7660_reg()
 * ����������Ĵ�����ַ  ����
 * ���������PASS/�ɹ�  FAIL/ʧ��
 * ����������OV7660 �Ĵ���д����
 */
int8u_t write_OV7660_reg(int8u_t reg_addr, int8u_t data);

/* �������ƣ�read_OV7660_reg()
 * ����������Ĵ�����ַ  ָ��
 * ���������PASS/�ɹ�  FAIL/ʧ��
 * ����������
 */
int8u_t read_OV7660_reg(int8u_t reg_addr, int8u_t *reg_ptr);

/* �������ƣ�OV766_device_id()
 * �����������
 * ���������PASS/�ɹ�  FAIL/ʧ��
 * ����������OV7660 �豸PID ���
 */
int8u_t OV766_device_id(void);

/* �������ƣ�OV7660_conf_window()
 * ���������ˮƽ����  ��ֱ����
 * �����������
 * ����������OV7660 ������������
 */
void OV7660_conf_window(int16u_t startx, int16u_t starty,
                               int16u_t width,  int16u_t height);

/* �������ƣ�OV7660_init()
 * �����������
 * ���������PASS/�ɹ�  FAIL/ʧ��
 * ����������OV7660 �ϵ縴λ��ʼ��
 */
int8u_t OV7660_init(void);
void OV7660_work();
void ov7070_pin_test();

#endif /* _OV7660_H */


