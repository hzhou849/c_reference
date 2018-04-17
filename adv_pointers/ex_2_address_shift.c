/* Memory simulation of register_address shift and storage

	create a pointer to a register and break the address up in a malloc created buffer and readback
	buffer[3] = register_address >> 24;
            buffer[2] = register_address >> 16;
            buffer[1] = register_address >> 8;
            buffer[0] = register_address & 0xff;

			iniitalize with 
			    // Fill in the register address,
    buffer[0] = buffer[1] = buffer[2] = buffer[3] = 0;*/

	int get_buff_length(char *) 
	{
		char *p = s;

		while (*p != '\0')
			p++;
		return p -s;
	}