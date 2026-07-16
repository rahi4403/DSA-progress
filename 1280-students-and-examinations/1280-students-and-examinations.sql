SELECT s.student_id,s.student_name,sub.subject_name, #we introduce the alias first because sql runs in this order- from -> join -> on-> where-> group by-> select -> oder by..so it automatically reads the aliases first,i.e, students as s,subjects name as sub and examinations as e
count(e.subject_name) as attended_exams
from Students as s
cross join Subjects as sub #we are using cross join to get 3 different tables together
left join Examinations as e
on s.student_id=e.student_id #s. and e. because we need the ids from student table to match with the ones from examination table so that we can match the correct names to the subject and ids and no of times exam taken
and sub.subject_name=e.subject_name #we add this extra condition so that ex- alice math matches only with  math and not with physics. There are 2 filters: same student & same subject for a particular id.
group by s.student_id,s.student_name,sub.subject_name # because it asks how many times ex- alice took math twice..so it needs to count twice.It helps the rows to be counted together
order by s.student_id,sub.subject_name; # sorts according to the id first then the subjects,alphabetically for each student
#basically the setup is like this: from->join->on(match rows)->where(remove rows)->group by->count->select->order by