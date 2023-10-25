module type BTREE = 
    type btree;
    type node;
    val is_empty : btree -> bool;
    val get_root : btree -> node;
    val get_sons : node -> node list;
    val get_label : node -> string;
end;;


