/*******************************************************
 * File name: net_tcp.c
 * Author:Chongguang Li
 * Versions:0.0.1
 * Description: the tcp api
 * History:
 *   1.Date:
 *     Author:
 *     Modification:
 *********************************************************/
#include "../../include/pando_net_tcp.h"
#include "../../../../peripherl/GSM_App.h"
#include "string.h"
#include "stdio.h"

static net_connected_callback tcp_connected_cb;
static net_sent_callback tcp_sent_cb;
static net_recv_callback tcp_recv_cb;

/******************************************************************************
 * FunctionName : net_tcp_connect
 * Description  : The function given as the connect
 * Parameters   : addr: the address used to listen the connection
 * 				  timeout: the connect timeout set value.
 * Returns      : none
*******************************************************************************/
void net_tcp_connect(struct net_tcp_addr addr, uint16 timeout)
{
	ST_NETWORKCONFIG net_addr;
	strcpy(net_addr.RemoteIP, addr.ip);
	sprintf(net_addr.RemotePort, "%d", addr.port);
	strcpy(net_addr.TransferMode, "TCP");
	if(addr.security == 1)
	{
		gprs_ssl_enable();
		while (0 != GPRS_LinkServer(&net_addr));
		// TODO: connect is block, need to add error process.
		if(tcp_connected_cb != NULL)
		{
			// TODO: add the connect code
			tcp_connected_cb();
		}
	}
	if(addr.security ==0)
	{
		gprs_ssl_disable();
		while (0 != GPRS_LinkServer(&net_addr));
		// TODO: connect is block, need to add error process.
		if(tcp_connected_cb != NULL)
		{
			tcp_connected_cb();
		}
	}

}

/******************************************************************************
 * FunctionName : net_tcp_register_connect_callback
 * Description  : it is used to specify the function that should be called when connected.
 * Parameters   : connected_cb: the specify function.
 * Returns      : none
*******************************************************************************/
void net_tcp_register_connected_callback(net_connected_callback connected_cb)
{
	tcp_connected_cb = connected_cb;
}

/******************************************************************************
 * FunctionName : net_tcp_send
 * Description  : The tcp send function.
 * Parameters   : buf: the data buffer to send.
 * 				  timeout: the sent timeout set value.
 * Returns      : none
*******************************************************************************/
void net_tcp_send(struct sys_buf buf, uint16 timeout)
{
	if(GPRS_SendData(buf.buf, buf.length) == 0)
	{
		if(tcp_sent_cb != NULL)
		{
			//TODO :add result no.
			tcp_sent_cb();
		}
	}
	// TODO: add error process.
}

/******************************************************************************
 * FunctionName : net_tcp_register_sent_callback
 * Description  : it is used to specify the function that should be called when sent.
 * Parameters   : connected_cb: the specify function.
 * Returns      : none
*******************************************************************************/
void net_tcp_register_sent_callback(net_sent_callback sent_cb)
{
	tcp_sent_cb = sent_cb;
}

/******************************************************************************
 * FunctionName : net_tcp_seriver_register_recv_callback
 * Description  : it is used to specify the function that should be called when received package.
 * Parameters   : recv_cb: the specify function.
 * Returns      : the listen result.
*******************************************************************************/
void net_tcp_seriver_register_recv_callback(net_server_recv_callback recv_cb)
{
	tcp_recv_cb = recv_cb;
}

