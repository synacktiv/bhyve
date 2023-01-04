#define e1000_PORT 0x2100

enum e1000_registers {

	CTRL = 0x00000,		/* Device Control - RW */

	/* Transmit */
	TXCW   = 0x0178,	/* x0178 transmit config */
	TCTL   = 0x0400,	/* x0400 transmit ctl */
	TIPG   = 0x0410,	/* x0410 inter-packet gap */
	AIT    = 0x0458,	/* x0458 Adaptive Interframe Throttle */
	TDBAL  = 0x3800,	/* x3800 desc table addr, low bits */
	TDBAH  = 0x3804,	/* x3804 desc table addr, hi 32-bits */
	TDLEN  = 0x3808,	/* x3808 # descriptors in bytes */
	TDH    = 0x3810,	/* x3810 desc table head idx */
	TDT    = 0x3818,	/* x3818 desc table tail idx */
	TIDV   = 0x3820,	/* x3820 intr delay */
	TXDCTL = 0x3828,	/* x3828 desc control */
	TADV   = 0x382c,	/* x382C intr absolute delay */

	/* Receive */
	RCTL	= 0x0100,	/* x0100 receive ctl */
	FCRTL	= 0x2160,	/* x2160 flow cntl thresh, low */
	FCRTH	= 0x2168,	/* x2168 flow cntl thresh, hi */
	RDBAL	= 0x2800,	/* x2800 desc table addr, low bits */
	RDBAH	= 0x2804,	/* x2804 desc table addr, hi 32-bits*/
	RDLEN	= 0x2808,	/* x2808 #descriptors */
	RDH	    = 0x2810,	/* x2810 desc table head idx */
	RDT	    = 0x2818,	/* x2818 desc table tail idx */
	RDTR	= 0x2820,	/* x2820 intr delay */
	RXDCTL	= 0x2828,	/* x2828 desc control */
	RADV	= 0x282c,	/* x282C intr absolute delay */
	RSRPD	= 0x2c00,	/* x2C00 recv small packet detect */
	RXCSUM  = 0x5000, 	/* x5000 receive cksum ctl */
};


/* Transmit Descriptor bit definitions */
#define E1000_TXD_DTYP_D	0x00100000 /* Data Descriptor */
#define E1000_TXD_DTYP_C	0x00000000 /* Context Descriptor */
#define E1000_TXD_POPTS_IXSM	0x01   /* Insert IP checksum */
#define E1000_TXD_POPTS_TXSM	0x02   /* Insert TCP/UDP checksum */
#define E1000_TXD_CMD_EOP	0x01000000 /* End of Packet */
#define E1000_TXD_CMD_IFCS	0x02000000 /* Insert FCS (Ethernet CRC) */
#define E1000_TXD_CMD_IC	0x04000000 /* Insert Checksum */
#define E1000_TXD_CMD_RS	0x08000000 /* Report Status */
#define E1000_TXD_CMD_RPS	0x10000000 /* Report Packet Sent */
#define E1000_TXD_CMD_DEXT	0x20000000 /* Desc extension (0 = legacy) */
#define E1000_TXD_CMD_VLE	0x40000000 /* Add VLAN tag */
#define E1000_TXD_CMD_IDE	0x80000000 /* Enable Tidv register */
#define E1000_TXD_STAT_DD	0x00000001 /* Descriptor Done */
#define E1000_TXD_STAT_EC	0x00000002 /* Excess Collisions */
#define E1000_TXD_STAT_LC	0x00000004 /* Late Collisions */
#define E1000_TXD_STAT_TU	0x00000008 /* Transmit underrun */
#define E1000_TXD_CMD_TCP	0x01000000 /* TCP packet */
#define E1000_TXD_CMD_IP	0x02000000 /* IP packet */
#define E1000_TXD_CMD_TSE	0x04000000 /* TCP Seg enable */
#define E1000_TXD_STAT_TC	0x00000004 /* Tx Underrun */
#define E1000_TXD_EXTCMD_TSTAMP	0x00000010 /* IEEE1588 Timestamp packet */

/* Transmit Control */
#define E1000_TCTL_EN		0x00000002 /* enable Tx */
#define E1000_TCTL_PSP		0x00000008 /* pad short packets */
#define E1000_TCTL_CT		0x00000ff0 /* collision threshold */
#define E1000_TCTL_COLD		0x003ff000 /* collision distance */
#define E1000_TCTL_RTLC		0x01000000 /* Re-transmit on late collision */
#define E1000_TCTL_MULR		0x10000000 /* Multiple request support */

/* Transmit descriptor types */
#define	E1000_TXD_MASK		(E1000_TXD_CMD_DEXT | 0x00F00000)
#define E1000_TXD_TYP_L		(0)
#define E1000_TXD_TYP_C		(E1000_TXD_CMD_DEXT | E1000_TXD_DTYP_C)
#define E1000_TXD_TYP_D		(E1000_TXD_CMD_DEXT | E1000_TXD_DTYP_D)

/* Receive Control */
#define E1000_RCTL_RST		0x00000001 /* Software reset */
#define E1000_RCTL_EN		0x00000002 /* enable */
#define E1000_RCTL_SBP		0x00000004 /* store bad packet */
#define E1000_RCTL_UPE		0x00000008 /* unicast promisc enable */
#define E1000_RCTL_MPE		0x00000010 /* multicast promisc enable */
#define E1000_RCTL_LPE		0x00000020 /* long packet enable */
#define E1000_RCTL_LBM_NO	0x00000000 /* no loopback mode */
#define E1000_RCTL_LBM_MAC	0x00000040 /* MAC loopback mode */
#define E1000_RCTL_LBM_TCVR	0x000000C0 /* tcvr loopback mode */
#define E1000_RCTL_DTYP_PS	0x00000400 /* Packet Split descriptor */
#define E1000_RCTL_RDMTS_HALF	0x00000000 /* Rx desc min thresh size */
#define E1000_RCTL_RDMTS_HEX	0x00010000
#define E1000_RCTL_RDMTS1_HEX	E1000_RCTL_RDMTS_HEX
#define E1000_RCTL_MO_SHIFT	12 /* multicast offset shift */
#define E1000_RCTL_MO_3		0x00003000 /* multicast offset 15:4 */
#define E1000_RCTL_BAM		0x00008000 /* broadcast enable */
/* these buffer sizes are valid if E1000_RCTL_BSEX is 0 */
#define E1000_RCTL_SZ_2048	0x00000000 /* Rx buffer size 2048 */
#define E1000_RCTL_SZ_1024	0x00010000 /* Rx buffer size 1024 */
#define E1000_RCTL_SZ_512	0x00020000 /* Rx buffer size 512 */
#define E1000_RCTL_SZ_256	0x00030000 /* Rx buffer size 256 */
/* these buffer sizes are valid if E1000_RCTL_BSEX is 1 */
#define E1000_RCTL_SZ_16384	0x00010000 /* Rx buffer size 16384 */
#define E1000_RCTL_SZ_8192	0x00020000 /* Rx buffer size 8192 */
#define E1000_RCTL_SZ_4096	0x00030000 /* Rx buffer size 4096 */
#define E1000_RCTL_VFE		0x00040000 /* vlan filter enable */
#define E1000_RCTL_CFIEN	0x00080000 /* canonical form enable */
#define E1000_RCTL_CFI		0x00100000 /* canonical form indicator */
#define E1000_RCTL_DPF		0x00400000 /* discard pause frames */
#define E1000_RCTL_PMCF		0x00800000 /* pass MAC control frames */
#define E1000_RCTL_BSEX		0x02000000 /* Buffer size extension */
#define E1000_RCTL_SECRC	0x04000000 /* Strip Ethernet CRC */

