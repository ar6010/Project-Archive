--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity reg is

	generic(n: positive := 8);

	port(
	
		d: in std_logic_vector(n-1 downto 0);
		rst, clk, ld: in std_logic;
		q: out std_logic_vector(n-1 downto 0)
	
	);
	
end reg;

architecture behav of reg is
begin

	memory: process(clk, rst, ld)
	begin
	
		if rising_edge(clk) then
			if rst = '1' then q <= (others => '0');
			elsif ld = '1' then q <= d;
			end if;
		end if;
		
	end process;

end architecture behav;