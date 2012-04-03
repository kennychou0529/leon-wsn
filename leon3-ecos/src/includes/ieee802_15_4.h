/*
 * ieee802_15_4.h
 *
 *  Created on: 2011-3-29
 *      Author: water
 */

#ifndef IEEE802_15_4_H_
#define IEEE802_15_4_H_

/* 802.15.4 frame type */
#define FRM_TYPE_BEACON			0x0
#define FRM_TYPE_DATA			0x1
#define FRM_TYPE_ACK			0x2
#define FRM_TYPE_CMD			0x3

/* Addressing modes */
#define NO_ADDRESS_FIELD		0x0
#define ADDR_MOD_RSVD			0x1
#define ADDR_MOD_16			0x2
#define ADDR_MOD_64			0x3

/* Frame Version */
#define FRM_VER_0			0x0		/* 802.15.4-2003 compatible */
#define FRM_VER_1			0x1		/* 802.15.4 frame */

typedef struct frm_ctrl
{
	U16 reserved1:1;
	U16 PAN_compress:1;
	U16 ack_req:1;
	U16 frm_pending:1;
	U16 security_en:1;
	U16 frm_type:3;

	U16 srcaddr_mode:2;
	U16 frm_ver:2;
	U16 dstaddr_mode:2;
	U16 reserved2:2;
} frm_ctrl_t;

typedef struct ieee15_4_mac_hdr {
	frm_ctrl_t frame_ctl;
	int8u_t sequence;
	int8u_t des_PANID[2];
	int8u_t des_ADDR[2];

	int8u_t src_PANID[2];
	int8u_t src_ADDR[2];
	int8u_t payload[0];
#define IEEE_MAC_LEN		11
} ieee_mac_hdr;
//__attribute__((packed));

#endif /* IEEE802_15_4_H_ */
