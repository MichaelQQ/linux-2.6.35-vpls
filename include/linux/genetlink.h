#ifndef __LINUX_GENERIC_NETLINK_H
#define __LINUX_GENERIC_NETLINK_H

#include <linux/types.h>
#include <linux/netlink.h>

#define GENL_NAMSIZ	16	/* length of family name */

#define GENL_MIN_ID	NLMSG_MIN_TYPE
#define GENL_MAX_ID	1023

struct genlmsghdr {
	__u8	cmd;
	__u8	version;
	__u16	reserved;
};

#define GENL_HDRLEN	NLMSG_ALIGN(sizeof(struct genlmsghdr))

#define GENL_ADMIN_PERM		0x01
#define GENL_CMD_CAP_DO		0x02
#define GENL_CMD_CAP_DUMP	0x04
#define GENL_CMD_CAP_HASPOL	0x08

/*
 * List of reserved static generic netlink identifiers:
 */
#define GENL_ID_GENERATE	0
#define GENL_ID_CTRL		NLMSG_MIN_TYPE

/**************************************************************************
 * Controller
 **************************************************************************/

enum {
	CTRL_CMD_UNSPEC,
	CTRL_CMD_NEWFAMILY,
	CTRL_CMD_DELFAMILY,
	CTRL_CMD_GETFAMILY,
	CTRL_CMD_NEWOPS,
	CTRL_CMD_DELOPS,
	CTRL_CMD_GETOPS,
	CTRL_CMD_NEWMCAST_GRP,
	CTRL_CMD_DELMCAST_GRP,
	CTRL_CMD_GETMCAST_GRP, /* unused */
	__CTRL_CMD_MAX,
};

#define CTRL_CMD_MAX (__CTRL_CMD_MAX - 1)

enum {
	CTRL_ATTR_UNSPEC,
	CTRL_ATTR_FAMILY_ID,
	CTRL_ATTR_FAMILY_NAME,
	CTRL_ATTR_VERSION,
	CTRL_ATTR_HDRSIZE,
	CTRL_ATTR_MAXATTR,
	CTRL_ATTR_OPS,
	CTRL_ATTR_MCAST_GROUPS,
	__CTRL_ATTR_MAX,
};

#define CTRL_ATTR_MAX (__CTRL_ATTR_MAX - 1)

enum {
	CTRL_ATTR_OP_UNSPEC,
	CTRL_ATTR_OP_ID,
	CTRL_ATTR_OP_FLAGS,
	__CTRL_ATTR_OP_MAX,
};

#define CTRL_ATTR_OP_MAX (__CTRL_ATTR_OP_MAX - 1)

enum {
	CTRL_ATTR_MCAST_GRP_UNSPEC,
	CTRL_ATTR_MCAST_GRP_NAME,
	CTRL_ATTR_MCAST_GRP_ID,
	__CTRL_ATTR_MCAST_GRP_MAX,
};

#define CTRL_ATTR_MCAST_GRP_MAX (__CTRL_ATTR_MCAST_GRP_MAX - 1)

enum {
	MPLS_CMD_UNSPEC,
	MPLS_CMD_NEWILM,
	MPLS_CMD_DELILM,
	MPLS_CMD_GETILM,
	MPLS_CMD_NEWNHLFE,
	MPLS_CMD_DELNHLFE,
	MPLS_CMD_GETNHLFE,
	MPLS_CMD_NEWXC,
	MPLS_CMD_DELXC,
	MPLS_CMD_GETXC,
	MPLS_CMD_SETLABELSPACE,
	MPLS_CMD_GETLABELSPACE,
	MPLS_CMD_ADDTUNNEL,
	MPLS_CMD_DELTUNNEL,
	__MPLS_CMD_MAX,
};

#define MPLS_CMD_MAX (__MPLS_CMD_MAX - 1)

enum {
	MPLS_ATTR_UNSPEC,
	MPLS_ATTR_ILM,
	MPLS_ATTR_NHLFE,
	MPLS_ATTR_XC,
	MPLS_ATTR_LABELSPACE,
	MPLS_ATTR_INSTR,
	MPLS_ATTR_STATS,
	MPLS_ATTR_TUNNEL,//add by here for create the tunnel interface
	__MPLS_ATTR_MAX,
};

#define MPLS_ATTR_MAX (__MPLS_ATTR_MAX - 1)

#ifdef __KERNEL__

/* All generic netlink requests are serialized by a global lock.  */
extern void genl_lock(void);
extern void genl_unlock(void);

#endif /* __KERNEL__ */

#endif	/* __LINUX_GENERIC_NETLINK_H */
