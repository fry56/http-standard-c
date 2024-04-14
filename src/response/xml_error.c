/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_error
*/

#include <xml.h>
#include <status_code.h>
#include <utils.h>

xml *xml_error(status_code_t code, char *msg)
{
    xml *xml = xml_new();
    xml_node *code_node;
    xml_node *msg_node;

    xml->root->tag = "error";
    code_node = xml_new_node(xml->root);
    code_node->tag = "code";
    code_node->inner_text = get_status_message(code);
    msg_node = xml_new_node(xml->root);
    msg_node->tag = "message";
    msg_node->inner_text = msg;
    return xml;
}
