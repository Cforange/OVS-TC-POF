#ifndef __LINUX_TC_ACT_TC_MPLS_WRAPPER_H
#define __LINUX_TC_ACT_TC_MPLS_WRAPPER_H 1

#if defined(__KERNEL__) || defined(HAVE_TCA_MPLS_TTL)
#include_next <linux/tc_act/tc_mpls.h>
#else

// SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause)
/* Copyright (C) 2019 Netronome Systems, Inc. */

#define TCA_MPLS_ACT_POP	1
#define TCA_MPLS_ACT_PUSH	2
#define TCA_MPLS_ACT_MODIFY	3
#define TCA_MPLS_ACT_DEC_TTL	4

struct tc_mpls {
       tc_gen;         /* generic TC action fields. */
       int m_action;   /* action of type TCA_MPLS_ACT_*. */
};

struct tc_add_field {
    tc_gen;
};

enum {
    TCA_ADD_FIELD_UNSPEC,
    TCA_ADD_FIELD_PARMS,
    TCA_ADD_FIELD_OFFSET,
    TCA_ADD_FIELD_LEN,
    TCA_ADD_FIELD_VALUE,
    __TCA_ADD_FIELD_MAX,
};
#define TCA_ADD_FIELD_MAX (__TCA_ADD_FIELD_MAX - 1)

enum {
       TCA_MPLS_UNSPEC,
       TCA_MPLS_TM,    /* struct tcf_t; time values associated with action. */
       TCA_MPLS_PARMS, /* struct tc_mpls; action type and general TC fields. */
       TCA_MPLS_PAD,
       TCA_MPLS_PROTO, /* be16; eth_type of pushed or next (for pop) header. */
       TCA_MPLS_LABEL, /* u32; MPLS label. Lower 20 bits are used. */
       TCA_MPLS_TC,    /* u8; MPLS TC field. Lower 3 bits are used. */
       TCA_MPLS_TTL,   /* u8; MPLS TTL field. Must not be 0. */
       TCA_MPLS_BOS,   /* u8; MPLS BOS field. Either 1 or 0. */
       __TCA_MPLS_MAX,
};
#define TCA_MPLS_MAX (__TCA_MPLS_MAX - 1)

#endif /* __KERNEL__ || HAVE_TCA_MPLS_TTL */

#endif /* __LINUX_TC_ACT_TC_MPLS_WRAPPER_H */
