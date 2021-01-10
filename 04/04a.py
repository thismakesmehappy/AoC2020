passports = open("input.txt")
count = 0
passport = {}
blank_line = 0

def split_line(line):
    return line.split(' ')

def build_passport(line):
    for item in line:
        question, answer = item.split(':')
        passport[question] = answer
        
def check_passport(passport):
    return (('byr' in passport) and
            ('iyr' in passport) and
            ('eyr' in passport) and
            ('hgt' in passport) and
            ('hcl' in passport) and
            ('ecl' in passport) and
            ('pid' in passport))


passports_lines = passports.readlines()
print(len(passports_lines))
for line in passports_lines:
    if line == '\n':
        blank_line += 1
        if (check_passport(passport)):
            count += 1
            print(blank_line, end='\t')
        passport = {}
    else:
        build_passport(split_line(line))
if (check_passport(passport)):
        count += 1
        print(count)
print(blank_line)
passports.close()
