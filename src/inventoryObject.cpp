InventoryObject::InventoryObject(string name, string description, string interaction, string collectionMessage);

void InventoryObject::interact()
{
  description = interaction;
  collect();
}

void InventoryObject::collect(Inventory *plrInventory)
{
  if (!collected)
  {
    plrInventory->addObject(this);
    collected = true;
  }
}