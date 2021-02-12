library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned;

entity addressDecoder is

	port(
	
		addr: in std_logic_vector(31 downto 0);
		memrd,memwr: in std_logic;
		ld2,ld1,ld0,datas: out std_logic
	
	);
	
end entity;

architecture df of addressDecoder is

begin

	ld2 <= '1' when memrd = '0' and memwr = '1' and addr < x"0000001F" else
				'0';
				
	ld1 <= '1' when memrd = '0' and memwr = '1' and addr = x"000000F8" else
				'0';
				
	ld0 <= '1' when memrd = '0' and memwr = '1' and addr = x"000000FC" else
				'0';
				
	datas <= '1' when memrd = '1' and memwr = '0' and addr < x"0000001F" else
				'0';
	

end architecture;