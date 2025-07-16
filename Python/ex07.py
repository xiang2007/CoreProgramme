age = {'Hans': 24, 'Prag': 23, 'Bunyod': 18}

print(age)
print(age.get('Hans'))

age['Prag'] = 30

print(age.get('Prag'))

age.pop('Bunyod')

print(age)