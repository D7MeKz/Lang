import {useState, useRef} from 'react';
import Practice2 from './practice2';

function CreateUser({ username, email, onChange, onCreate }) {
    return (
      <div>
        <input
          name="username"
          placeholder="계정명"
          onChange={onChange}
          value={username}
        />
        <input
          name="email"
          placeholder="이메일"
          onChange={onChange}
          value={email}
        />
        <button onClick={onCreate}>등록</button>
      </div>
    );
}

function Practice3() {
    const [inputs, setInputs] = useState({
      username: '',
      email: ''
    });
    const { username, email } = inputs;
    const onChange = e => {
      const { name, value } = e.target;
      setInputs({
        ...inputs,
        [name]: value
      });
    };
    const users = [
      {
        id: 1,
        username: 'velopert',
        email: 'public.velopert@gmail.com'
      },
      {
        id: 2,
        username: 'tester',
        email: 'tester@example.com'
      },
      {
        id: 3,
        username: 'liz',
        email: 'liz@example.com'
      }
    ];
  
    const nextId = useRef(4);
    const onCreate = () => {

  
      setInputs({
        username: '',
        email: ''
      });
      nextId.current += 1;
    };
    return (
      <>
        <CreateUser
          username={username}
          email={email}
          onChange={onChange}
          onCreate={onCreate}
        />
        <Practice2 users={users} />
      </>
    );
  }
  
export default Practice3;