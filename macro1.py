class MNT:
    def __init__(self, macro_name, mdt_index):
        self.m_name = macro_name
        self.mdt_index = mdt_index

    def __repr__(self):
        return f'{self.m_name}\t{self.mdt_index}'


mnt = []
mdt = []

source_file = open('abc.txt', 'r')
file_content = source_file.readlines()
source_file.close()
line_counter = 0

while line_counter < len(file_content):
    line = file_content[line_counter]
    line_counter += 1
    if 'macro' not in line.lower():
        print(line, end='')
    else:
        line = file_content[line_counter]
        line_counter += 1

        temp = line.split()
        macro_name = temp[0]
        mnt.append(MNT(macro_name, len(mdt)))

        while line_counter < len(file_content):
            mdt.append(line)
            if 'mend' in line.lower():
                break

            line = file_content[line_counter]
            line_counter += 1


print('\n-------------MNT TABLE ----------')
print(f'index          Macro name           MDT index')
for index, macro in enumerate(mnt):
    print(f'{index}          {macro.m_name}          {macro.mdt_index}')

print('----------------MDT TABLE-------------')
print(f'{"mdtindex":<10}{"macro definition":<10}')
for index, macro_def in enumerate(mdt):
    print(f'{index:<10}{macro_def.strip():<10}')

# Pass 2:

print('---------Macro expansion-------------')

line_counter = 0
num_macros = 0
macro_names = [mac.m_name for mac in mnt]

while num_macros < len(mnt):
    line = file_content[line_counter]
    line_counter += 1
    if 'mend' in line.lower():
        num_macros += 1
in_macro_def = False
while line_counter < len(file_content):
    line = file_content[line_counter]
    line_counter += 1
    if 'macro' in line.lower():
        in_macro_def = True
    elif 'mend' in line.lower():
        in_macro_def = False
    if not in_macro_def:
        if line.split()[0] not in macro_names:
            print(line, end='')
        else:
            mnt_record = mnt[macro_names.index(line.split()[0])]
            mdt_index = mnt_record.mdt_index
            cur_def = mdt[mdt_index]
            formal_parameters = cur_def.split()[1:]
            actual_parameters = line.split()[1:]
            param_values = {k: v for k, v in zip(formal_parameters, actual_parameters)}
            mdt_index += 1
            cur_def = mdt[mdt_index]
            while 'mend' not in cur_def.lower():
                mnemonics = cur_def.split()
                for index, mnemonic in enumerate(mnemonics):
                    if mnemonic.startswith('&'):
                        mnemonics[index] = param_values[mnemonic]
                print(' '.join(mnemonics))
                mdt_index += 1
                cur_def = mdt[mdt_index]




